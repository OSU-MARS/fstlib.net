#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "FactorVector.h"
#include "StringColumn.h"

class FactorVectorAdapter : public IFactorColumn
{
	std::shared_ptr<FactorVector> shared_data;

public:
	FactorVectorAdapter(unsigned long long length, unsigned long long nr_of_levels, FstColumnAttribute columnAttribute)
	{
		shared_data = std::make_shared<FactorVector>(length);

		StringColumn* levels = shared_data->Levels();
		levels->AllocateVec(nr_of_levels);
	}

	~FactorVectorAdapter()
	{
	}

	int* LevelData()
	{
		return shared_data->Data();
	}

	IStringColumn* Levels()
	{
		return shared_data->Levels();
	}

	std::shared_ptr<FactorVector> DataPtr() const
	{
		return shared_data;
	}
};
