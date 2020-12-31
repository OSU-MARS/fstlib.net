#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "IntVector.h"

class IntVectorAdapter : public IIntegerColumn
{
	std::shared_ptr<IntVector> shared_data;
	FstColumnAttribute columnAttribute;
	short int scale;
	std::string annotation;

public:
	IntVectorAdapter(unsigned long long length, FstColumnAttribute columnAttribute, short int scale)
	{
		shared_data = std::make_shared<IntVector>(length);
		this->columnAttribute = columnAttribute;
		this->scale = scale;
	}

	~IntVectorAdapter()
	{
	}

	FstColumnAttribute Attribute()
	{
		return columnAttribute;
	}

	short int Scale()
	{
		return scale;
	}

	int* Data()
	{
		return shared_data->Data();
	}

	std::shared_ptr<DestructableObject> DataPtr() const
	{
		return shared_data;
	}

	void Annotate(std::string annotation)
	{
		this->annotation = annotation;
	}
};