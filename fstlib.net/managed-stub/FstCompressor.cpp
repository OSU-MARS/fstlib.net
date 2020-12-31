#include "pch.h"

#include "FstCompressor.h"
#include "../fsttable/TypeFactory.h"

namespace Fst
{
	FstCompressor::FstCompressor()
	{
		this->unmanagedCompressor = new ::FstCompressor(nullptr);
	}

	FstCompressor::FstCompressor(CompressionAlgorithm compressionAlgorithm, int compressionLevel)
	{
		this->unmanagedCompressor = new ::FstCompressor(static_cast<COMPRESSION_ALGORITHM>(compressionAlgorithm), (unsigned int)compressionLevel, new TypeFactory());
	}

	FstCompressor::~FstCompressor()
	{
		delete this->unmanagedCompressor;
	}

	IBlobContainer^ FstCompressor::CompressBlob(array<Byte>^ blob, bool hash)
	{
		pin_ptr<unsigned char> pinnedBlob = &blob[0];
		::IBlobContainer* unmanagedContainer = this->unmanagedCompressor->CompressBlob(pinnedBlob, blob->LongLength, hash);
		return nullptr; // TODO: managed wrapper
	}

	IBlobContainer^ FstCompressor::DecompressBlob(array<Byte>^ blob, bool checkHashes)
	{
		pin_ptr<unsigned char> pinnedBlob = &blob[0];
		::IBlobContainer* unmanagedContainer = this->unmanagedCompressor->DecompressBlob(pinnedBlob, blob->LongLength, checkHashes);
		return nullptr; // TODO: managed wrapper
	}
}