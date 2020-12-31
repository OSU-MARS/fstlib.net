#include "pch.h"

#include "FstTable.h"
#include "StringExtensions.h"

#include "../fstlib.net/fsttable/ColumnFactory.h"
#include "../fstlib.net/fsttable/FstTable.h"
#include "../fstlib/interface/fststore.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace Fst
{
    FstTable::FstTable()
    {
        this->columns = gcnew List<FstColumn^>();
    }

	void FstTable::Write(String^ filePath, int compressionFactor)
	{
        if ((compressionFactor < 0) || (compressionFactor > 100))
        {
            throw gcnew ArgumentOutOfRangeException("compressionFactor");
        }

        int rows = Int64::MinValue;
        for each(FstColumn^ column in this->columns)
        {
            rows = Math::Min(rows, column->Length);
        }

        ::ColumnFactory unmanagedColumnFactory = ::ColumnFactory();
        ::FstTable unmanagedTable = ::FstTable();
        unmanagedTable.InitTable(this->Columns->Count, rows);
        for (int columnIndex = 0; columnIndex < this->Columns->Count; ++columnIndex)
        {
            FstColumn^ column = this->Columns[columnIndex];
            array<unsigned char>^ source;

            ::IByteColumn* byteColumn = static_cast<::IColumnFactory*>(&unmanagedColumnFactory)->CreateByteColumn(rows, ::FstColumnAttribute::BYTE_BASE);
            Marshal::Copy(source, 0, (IntPtr)byteColumn->Data(), rows);
            unmanagedTable.SetByteColumn(byteColumn, columnIndex);
        }

        std::string unmanagedFilePath = StringExtensions::ToNative(filePath);
        ::FstStore unmanagedStore(unmanagedFilePath);
        unmanagedStore.fstWrite(unmanagedTable, compressionFactor);
    }
}