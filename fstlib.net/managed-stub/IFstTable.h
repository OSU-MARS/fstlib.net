#pragma once
#include "../managed/FstColumnType.h"
#include "FstColumnAttribute.h"
#include "IByteColumn.h"
#include "IDoubleColumn.h"
#include "IFactorColumn.h"
#include "IInt32Column.h"
#include "IInt64Column.h"
#include "ILogicalColumn.h"
#include "IStringColumn.h"
#include "IStringWriter.h"
using namespace System;

namespace Fst
{
	public interface class IFstTable
    {
    public:
        FstColumnType ColumnType(unsigned int colNr, FstColumnAttribute columnAttribute, int scale, String^ annotation, bool hasAnnotation);

        // Writer interface
        IStringWriter^ GetStringWriter(unsigned int colNr);
        array<int>^ GetLogicalWriter(unsigned int colNr);
        array<int>^ GetIntWriter(unsigned int colNr);
        array<Int64>^ GetInt64Writer(unsigned int colNr);
        array<Byte>^ GetByteWriter(unsigned int colNr);
        array<double>^ GetDoubleWriter(unsigned int colNr);
        IStringWriter^ GetLevelWriter(unsigned int colNr);
        IStringWriter^ GetColNameWriter();
        void GetKeyColumns(int keyColPos);
        property int Columns

        {
            int get();
        }

        property int KeyCount
        {
            int get();
        }

        property int Rows
        {
            int get();
        }

        // Reader interface
        void InitTable(unsigned int nrOfCols, unsigned long long nrOfRows);
        void SetStringColumn(IStringColumn^ stringColumn, int colNr);
        void SetLogicalColumn(ILogicalColumn^ logicalColumn, int colNr);
        void SetIntegerColumn(IInt32Column^ integerColumn, int colNr);
        void SetDoubleColumn(IDoubleColumn^ doubleColumn, int colNr);
        void SetFactorColumn(IFactorColumn^ factorColumn, int colNr);
        void SetInt64Column(IInt64Column^ int64Column, int colNr);
        void SetByteColumn(IByteColumn^ byteColumn, int colNr);

        // use more efficient string container here (e.g. std::vector<string>)
        void SetColNames(IStringArray^ col_names);
        void SetKeyColumns(int* keyColPos, unsigned int nrOfKeys);
    };
}

