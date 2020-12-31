#pragma once
#include <interface/icolumnfactory.h>
#include "FstTable.h"

class ColumnFactory : public IColumnFactory
{
	// Inherited via IColumnFactory
	IFactorColumn* CreateFactorColumn(int nrOfRows, int nrOfLevels, FstColumnAttribute columnAttribute)
	{
		return new FactorVectorAdapter(nrOfRows, nrOfLevels, columnAttribute);
	}

	ILogicalColumn* CreateLogicalColumn(int nrOfRows, FstColumnAttribute columnAttribute)
	{
		return new LogicalVectorAdapter(nrOfRows);
	}

	IInt64Column* CreateInt64Column(int nrOfRows, FstColumnAttribute columnAttribute, short int scale)
	{
		return new Int64VectorAdapter(nrOfRows, columnAttribute, scale);
	}

	IDoubleColumn* CreateDoubleColumn(int nrOfRows, FstColumnAttribute columnAttribute, short int scale)
	{
		return new DoubleVectorAdapter(nrOfRows, columnAttribute, scale);
	}

	IIntegerColumn* CreateIntegerColumn(int nrOfRows, FstColumnAttribute columnAttribute, short int scale)
	{
		return new IntVectorAdapter(nrOfRows, columnAttribute, scale);
	}

	IByteColumn* CreateByteColumn(int nrOfRows, FstColumnAttribute columnAttribute)
	{
		return new ByteVectorAdapter(nrOfRows, columnAttribute);
	}

	IStringColumn* CreateStringColumn(int nrOfRows, FstColumnAttribute columnAttribute)
	{
		return new StringColumn();
	}

	IStringArray* CreateStringArray()
	{
		return nullptr;
	}
};