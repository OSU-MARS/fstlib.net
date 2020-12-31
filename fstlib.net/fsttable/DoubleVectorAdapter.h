#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "DoubleVector.h"

class DoubleVectorAdapter : public IDoubleColumn
{
	std::shared_ptr<DoubleVector> shared_data;
	FstColumnAttribute columnAttribute;
	std::string annotation;
	short int scale;

public:
	DoubleVectorAdapter(unsigned long long length, FstColumnAttribute columnAttribute, short int scale)
	{
		shared_data = std::make_shared<DoubleVector>(length);
		this->columnAttribute = columnAttribute;
		this->scale = scale;
	}

	~DoubleVectorAdapter()
	{
	}

	double* Data()
	{
		return shared_data->Data();
	}

	std::shared_ptr<DoubleVector> DataPtr()
	{
		return shared_data;
	}

	void Annotate(std::string annotation)
	{
		this->annotation = annotation;
	}

	std::string Attribute() const
	{
		return annotation;
	}
};
