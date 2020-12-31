#pragma once
#include "FstColumnAttribute.h"
#include "IByteColumn.h"
#include "IDoubleColumn.h"
#include "IFactorColumn.h"
#include "IInt32Column.h"
#include "IInt64Column.h"
#include "ILogicalColumn.h"
#include "IStringArray.h"
#include "IStringColumn.h"

namespace Fst
{
	public interface class IColumnFactory
	{
	public:
		IFactorColumn^ CreateFactorColumn(int nrOfRows, int nrOfLevels, FstColumnAttribute columnAttribute);
		ILogicalColumn^ CreateLogicalColumn(int nrOfRows, FstColumnAttribute columnAttribute);
		IDoubleColumn^ CreateDoubleColumn(int nrOfRows, FstColumnAttribute columnAttribute, int scale);
		IInt32Column^ CreateIntegerColumn(int nrOfRows, FstColumnAttribute columnAttribute, int scale);
		IByteColumn^ CreateByteColumn(int nrOfRows, FstColumnAttribute columnAttribute);
		IInt64Column^ CreateInt64Column(int nrOfRows, FstColumnAttribute columnAttribute, int scale);
		IStringColumn^ CreateStringColumn(int nrOfRows, FstColumnAttribute columnAttribute);
		IStringArray^ CreateStringArray();
	};
}