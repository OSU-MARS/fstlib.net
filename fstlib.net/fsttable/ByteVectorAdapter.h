#pragma once
#include <memory>
#include <interface/ifsttable.h>
#include "ByteVector.h"

class ByteVectorAdapter : public IByteColumn
{
	std::shared_ptr<ByteVector> shared_data;

public:
	ByteVectorAdapter(unsigned long long length, FstColumnAttribute columnAttribute = FstColumnAttribute::NONE)
	{
		shared_data = std::make_shared<ByteVector>(length);
	}

	~ByteVectorAdapter()
	{
	}

	char* Data()
	{
		return shared_data->Data();
	}

	std::shared_ptr<DestructableObject> DataPtr() const
	{
		return shared_data;
	}
};
