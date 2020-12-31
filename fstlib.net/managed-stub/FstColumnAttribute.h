#pragma once
#include "..\fstlib\interface\ifstcolumn.h"

namespace Fst
{
	// Column attributes available in fst
	// Only add to the end to support previous format versions
	public enum class FstColumnAttribute
	{
		None = ::FstColumnAttribute::NONE,                                                // unknown type
		CharacterBase = ::FstColumnAttribute::CHARACTER_BASE,                             // default character type
		FactorBase = ::FstColumnAttribute::FACTOR_BASE,                                   // default factor type (character vector levels with integer vector)
		FactorOrdered = ::FstColumnAttribute::FACTOR_ORDERED,                             // factor with ordered levels
		Int32Base = ::FstColumnAttribute::INT_32_BASE,                                    // default integer type
		Int32TimestampSeconds = ::FstColumnAttribute::INT_32_TIMESTAMP_SECONDS,           // number of seconds since epoch. Annotation holds the timezone.
		Int32TimeIntervalSeconds = ::FstColumnAttribute::INT_32_TIMEINTERVAL_SECONDS,     // number of fractional seconds between two moments in time.
		Int32DateDays = ::FstColumnAttribute::INT_32_DATE_DAYS,                           // number of days since epoch
		Int32TimeOfDaySeconds = ::FstColumnAttribute::INT_32_TIME_OF_DAY_SECONDS,         // number of seconds since the start of day [scale is FstTimeScale enum]
		DoubleBase = ::FstColumnAttribute::DOUBLE_64_BASE,                                // default double type
		DoubleDateDays = ::FstColumnAttribute::DOUBLE_64_DATE_DAYS,                       // number of days since epoch
		DoubleTimestampSeconds = ::FstColumnAttribute::DOUBLE_64_TIMESTAMP_SECONDS,       // number of fractional seconds since epoch. Annotation holds the timezone.
		DoubleTimeIntervalSeconds = ::FstColumnAttribute::DOUBLE_64_TIMEINTERVAL_SECONDS, // number of fractional seconds between two moments in time [scale is FstTimeScale enum]
		DoubleTimeOfDaySeconds = ::FstColumnAttribute::DOUBLE_64_TIME_OF_DAY_SECONDS,     // number of seconds since the start of day [scale is FstTimeScale enum]
		BooleanBase = ::FstColumnAttribute::BOOL_2_BASE,                                  // 3 value boolean: 0 (false), 1 (true) and INT_MIN (NA)
		Int64Base = ::FstColumnAttribute::INT_64_BASE,                                    // default int64 type
		Int64TimeSeconds = ::FstColumnAttribute::INT_64_TIME_SECONDS,                     // number of seconds since epoch [scale is FstTimeScale enum]
		ByteBase = ::FstColumnAttribute::BYTE_BASE                                        // default byte type
	};
}
