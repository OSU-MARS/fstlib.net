#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "LongVector.h"

class Int64VectorAdapter : public IInt64Column
{
	std::shared_ptr<LongVector> shared_data;
	FstColumnAttribute columnAttribute;
	short int scale;

public:
	Int64VectorAdapter(unsigned long long length, FstColumnAttribute columnAttribute, short int scale)
	{
		shared_data = std::make_shared<LongVector>(length);
		this->columnAttribute = columnAttribute;
		this->scale = scale;
	}

	~Int64VectorAdapter()
	{
	}

	long long* Data()
	{
		return shared_data->Data();
	};

	std::shared_ptr<LongVector> DataPtr() const
	{
		return shared_data;
	}

	FstColumnAttribute ColumnAttribute() const
	{
		return columnAttribute;
	}

};
