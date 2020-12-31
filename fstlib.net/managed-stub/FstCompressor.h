#pragma once
#include "..\fstlib\interface\fstcompressor.h"

#include "CompressionAlgorithm.h"
#include "IBlobContainer.h"
#include "ITypeFactory.h"

using namespace System;

namespace Fst
{
	public ref class FstCompressor
	{
    private:
        ::FstCompressor* unmanagedCompressor;

    public:
        FstCompressor();

        /// <summary>
        /// constructor for an FstCompressor object
        /// </summary>
        /// <param name="compressionAlgorithm">algorithm to use for compression</param>
        /// <param name="compressionLevel">compression level between 0 and 100</param>
        FstCompressor(CompressionAlgorithm compressionAlgorithm, int compressionLevel);
        ~FstCompressor();

        IBlobContainer^ CompressBlob(array<unsigned char>^ blob_source, bool hash);
        IBlobContainer^ DecompressBlob(array<unsigned char>^ blobSource, bool checkHashes);
    };
}