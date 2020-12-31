#pragma once
#include "DestructableObject.h"

class DoubleVector : public DestructableObject
{
	double* data;

public:
	DoubleVector(unsigned long long length)
	{
		this->data = new double[length];
	}

	~DoubleVector()
	{
		delete[] data;
	}

	double* Data()
	{
		return data;
	}

};
