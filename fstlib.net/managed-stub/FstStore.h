#pragma once

#include <interface/fststore.h>

#include "FstColumnScale.h"
#include "IColumnFactory.h"
#include "IFstTable.h"
#include "IStringArray.h"
#include "IStringColumn.h"
using namespace System;

namespace Fst
{
	public ref class FstStore
	{
    private:
        ::IColumnFactory* unmanagedColumnFactory;
        ::FstStore* unmanagedStore;
        String^ fstFile;

    public:
        //property array<FstColumnAttribute>^ ColumnAttributes
        //{
        //    array<FstColumnAttribute>^ get()
        //    {
        //        return this->columnAttributes;
        //    }
        //}

        //property int Columns
        //{
        //    int get() { return this->unmanagedStore->nrOfCols; }
        //}

        //property array<FstColumnScale>^ ColumnScales
        //{
        //    array<FstColumnScale>^ get()
        //    {
        //        return this->columnScales;
        //    }
        //}

        //property array<FstColumnType>^ ColumnTypes
        //{
        //    array<FstColumnType>^ get()
        //    {
        //        return this->columnTypes;
        //    }
        //}

        // TODO: unsigned short int* colBaseTypes; // what is this used for? how is it different from ColumnTypes?

        //property int KeyColumnPosition
        //{
        //    int get() { return *this->unmanagedStore->keyColPos; }
        //    void set(int value) { *this->unmanagedStore->keyColPos = value; }
        //}

        //property int KeyLength
        //{
        //    int get() { return this->unmanagedStore->keyLength; }
        //}

        //property int MaximumTableVersion
        //{
        //    int get() { return this->unmanagedStore->tableVersionMax; }
        //}

        //property array<String^>^ Metadata
        //{
        //    array<String^>^ get()
        //    {
        //        return this->metadataBlock;
        //    }
        //}

        //property int Rows
        //{
        //    int get();
        //    void set(int alue);
        //}

        FstStore(String^ fstFilePath);
        ~FstStore();

        //void Metadata(IColumnFactory^ columnFactory, IStringColumn^ columnNames);

        //void Read(IFstTable^ tableReader, IStringArray^ columnSelection, int startRow, int endRow,
        //    IColumnFactory^ columnFactory, array<int>^ keyIndex, IStringArray^ selectedColumns, IStringColumn^ columnNames);

        /// <summary>
        /// Stream a data table
        /// </summary>
        /// <param name="fstTable">Table to stream, implementation of IFstTable interface.</param>
        /// <param name="compress">Compression factor with a value 0 - 100.</param>
        void Write(IFstTable^ table, int compressionFactor);
    };
}

