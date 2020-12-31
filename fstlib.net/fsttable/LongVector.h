#pragma once
#include "DestructableObject.h"

class LongVector : public DestructableObject
{
	long long* data;

public:
	LongVector(unsigned long long length)
	{
		this->data = new long long[length];
	}

	~LongVector()
	{
		delete[] data;
	}

	long long* Data()
	{
		return data;
	}
};
