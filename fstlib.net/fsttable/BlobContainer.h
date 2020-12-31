#pragma once
#include <memory>
#include <interface/fstcompressor.h>

#include "Blob.h"

class BlobContainer : public IBlobContainer
{
	std::shared_ptr<Blob> shared_data;

	unsigned long long blobSize = 0;

public:
	BlobContainer(unsigned long long size)
	{
		shared_data = std::make_shared<Blob>(size);
		blobSize = size;
	}

	unsigned char* Data()
	{
		return shared_data->Data();
	}

	std::shared_ptr<Blob> DataPtr() const
	{
		return shared_data;
	}

	unsigned long long Size()
	{
		return blobSize;
	}
};
