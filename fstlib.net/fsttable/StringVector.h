#pragma once
#include <string>
#include <vector>
#include "DestructableObject.h"

class StringVector : public DestructableObject
{
	std::vector<std::string>* data;

public:
	StringVector(unsigned long long vecLength)
	{
		this->data = new std::vector<std::string>(vecLength);
	}

	~StringVector()
	{
		delete data;
	}

	std::vector<std::string>* StrVec() const { return data; }
};
