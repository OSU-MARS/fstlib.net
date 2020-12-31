#pragma once
#include "DestructableObject.h"

class ByteVector : public DestructableObject
{
	char* data;

public:
	ByteVector(unsigned long long length)
	{
		this->data = new char[length];
	}

	~ByteVector()
	{
		delete[] data;
	}

	char* Data()
	{
		return data;
	}
};