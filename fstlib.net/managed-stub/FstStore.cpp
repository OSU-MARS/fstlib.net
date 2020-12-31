#include "pch.h"

#include "../fsttable/columnfactory.h"
#include "../fsttable/fsttable.h"
#include "FstStore.h"
#include "../managed/StringExtensions.h"
using namespace System;

namespace Fst
{
    FstStore::FstStore(String^ fstFilePath)
    {
        std::string unmanagedFilePath = StringExtensions::ToNative(fstFilePath);
        this->unmanagedColumnFactory = new ::ColumnFactory();
        this->unmanagedStore = new ::FstStore(unmanagedFilePath);
    }

    FstStore::~FstStore()
    {
        delete this->unmanagedColumnFactory;
        delete this->unmanagedStore;
    }

    //void FstStore::Metadata(IColumnFactory^ columnFactory, IStringColumn^ columnNames)
    //{
    //    this->unmanagedStore->fstMeta(, );
    //}

    //void FstStore::Read(IFstTable^ tableReader, IStringArray^ columnSelection, int startRow, int endRow,
    //    IColumnFactory^ columnFactory, array<int>^ keyIndex, IStringArray^ selectedColumns, IStringColumn^ columnNames)
    //{
    //    this->unmanagedStore->fstRead(, , startRow, endRow, , , , );
    //}

    void FstStore::Write(IFstTable^ table, int compressionFactor)
    {
        if ((compressionFactor < 0) || (compressionFactor > 100))
        {
            throw gcnew ArgumentOutOfRangeException("compressionFactor");
        }
        if (table == nullptr)
        {
            throw gcnew ArgumentNullException("table");
        }

        ::FstTable unmanagedTable = ::FstTable();
        unmanagedTable.InitTable(table->Columns, table->Rows);
        for (int columnIndex = 0; columnIndex < table->Columns; ++columnIndex)
        {
            ::IByteColumn* byteColumn = this->unmanagedColumnFactory->CreateByteColumn(table->Rows, ::FstColumnAttribute::BYTE_BASE);
            
            unmanagedTable.SetByteColumn(byteColumn, columnIndex);
        }
        this->unmanagedStore->fstWrite(unmanagedTable, compressionFactor);
    }
}