#pragma once
#include "../fstlib/interface/fsthash.h"
using namespace System;

namespace Fst
{
	public ref class FstHasher
	{
	private:
		::FstHasher* unmanagedHasher;

	public:
		FstHasher();
		~FstHasher();

		/// <summary>
		/// Calculate 64 - bit xxHash of an arbitrary length input vector
		/// </summary>
		/// <param name="blob">input buffer for hash calculation</param>
		/// <param name="multithreadedBlocked">if true, use a multi - threaded blocked hash format (hash of hashes)</param>
		/// <returns>hash value of the input buffer</returns>
		UInt64 HashBlob(array<Byte>^ blob, bool multithreadedBlocked);

		/// </summary>
		/// <param name="blob">input buffer for hash calculation</param>
		/// <param name="seed">Seed for hashing</param>
		/// <param name="multithreadedBlocked">if true, use a multi - threaded blocked hash format (hash of hashes)</param>
		/// <returns>hash value of the input buffer</returns>
		UInt64 HashBlobSeed(array<Byte>^ blob, UInt64 seed, bool multithreadedBlocked);
	};
}
