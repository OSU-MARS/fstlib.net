#pragma once
#include "..\fstlib\interface\istringwriter.h"

namespace Fst
{
	public enum class StringEncoding
	{
		Native = ::StringEncoding::NATIVE,
		Latin1 = ::StringEncoding::LATIN1,
		Utf8 = ::StringEncoding::UTF8
	};
}