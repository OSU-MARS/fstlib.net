#pragma once
#include <interface/fstcompressor.h>

#include "BlobContainer.h"

class TypeFactory : public ITypeFactory
{
public:
	~TypeFactory() {}

	IBlobContainer* CreateBlobContainer(unsigned long long size)
	{
		return new BlobContainer(size);
	}
};