#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "IntVector.h"

class LogicalVectorAdapter : public ILogicalColumn
{
	std::shared_ptr<IntVector> shared_data;

public:
	LogicalVectorAdapter(unsigned long long length)
	{
		shared_data = std::make_shared<IntVector>(length);
	}

	~LogicalVectorAdapter()
	{
	}

	int* Data()
	{
		return shared_data->Data();
	}

	std::shared_ptr<IntVector> DataPtr() const
	{
		return shared_data;
	}
};
