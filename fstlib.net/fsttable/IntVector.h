#pragma once
#include "DestructableObject.h"

class IntVector : public DestructableObject
{
	int* data;

public:
	IntVector(unsigned long long length)
	{
		this->data = new int[length];
	}

	~IntVector()
	{
		delete[] data;
	}

	int* Data()
	{
		return data;
	}
};
