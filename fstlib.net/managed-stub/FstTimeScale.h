#pragma once
#include "..\fstlib\interface\ifstcolumn.h"

namespace Fst
{
	// Available time scales
	// Only add to the end to support previous format versions
	public enum class FstTimeScale
	{
		Nanoseconds = ::FstTimeScale::NANOSECONDS,
		Microseconds = ::FstTimeScale::MICROSECONDS,
		Milliseconds = ::FstTimeScale::MILLISECONDS,
		Seconds = ::FstTimeScale::SECONDS,
		Minutes = ::FstTimeScale::MINUTES,
		Hours = ::FstTimeScale::HOURS,
		Days = ::FstTimeScale::DAYS,
		Years = ::FstTimeScale::YEARS
	};
}
