#pragma once
#include "..\fstlib\interface\fstcompressor.h"

namespace Fst
{
	public enum class CompressionAlgorithm
	{
		None = COMPRESSION_ALGORITHM::ALGORITHM_NONE,
		LZ4 = COMPRESSION_ALGORITHM::ALGORITHM_LZ4,
		ZStd = COMPRESSION_ALGORITHM::ALGORITHM_ZSTD
	};
}