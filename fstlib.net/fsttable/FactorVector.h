#pragma once
#include "DestructableObject.h"
#include "StringColumn.h"

class FactorVector : public DestructableObject
{
	int* data = nullptr;
	StringColumn* levels;
	unsigned long long length;

public:
	FactorVector(unsigned long long length)
	{
		this->length = length;
		if (length > 0)
		{
			this->data = new int[length];
		}
		this->levels = new StringColumn();  // AllocVector HAS to be called?
	}

	~FactorVector()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
		delete levels;
	}

	int* Data()
	{
		return data;
	}

	StringColumn* Levels() const
	{
		return levels;
	}
};
