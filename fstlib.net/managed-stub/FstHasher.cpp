#include "pch.h"

#include "FstHasher.h"

namespace Fst
{
	FstHasher::FstHasher()
	{
		this->unmanagedHasher = new ::FstHasher();
	}

	FstHasher::~FstHasher()
	{
		delete this->unmanagedHasher;
	}

	UInt64 FstHasher::HashBlob(array<Byte>^ blob, bool multithreadedBlocked)
	{
		pin_ptr<unsigned char> unmanagedBlob = &blob[0];
		return this->unmanagedHasher->HashBlob(unmanagedBlob, blob->LongLength, multithreadedBlocked);
	}

	UInt64 FstHasher::HashBlobSeed(array<Byte>^ blob, UInt64 seed, bool multithreadedBlocked)
	{
		pin_ptr<unsigned char> unmanagedBlob = &blob[0];
		return this->unmanagedHasher->HashBlobSeed(unmanagedBlob, blob->LongLength, seed, multithreadedBlocked);
	}
}