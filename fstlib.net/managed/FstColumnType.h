#pragma once
#include "../fstlib/interface/ifstcolumn.h"

namespace Fst
{
	public enum class FstColumnType
	{
		Unknown = ::FstColumnType::UNKNOWN,
		Character = ::FstColumnType::CHARACTER, // character vector
		Factor = ::FstColumnType::FACTOR, // factor with character vector levels (0 = NA)
		Int32 = ::FstColumnType::INT_32, // 32-bit signed integer vector
		Double = ::FstColumnType::DOUBLE_64, // 64-bit double vector
		Boolean = ::FstColumnType::BOOL_2, // 2-bit boolean value (00 = false, 01 = true and 10 = NA)
		Int64 = ::FstColumnType::INT_64, // 64-bit signed integer vector
		Byte = ::FstColumnType::BYTE // byte vector
	};
}