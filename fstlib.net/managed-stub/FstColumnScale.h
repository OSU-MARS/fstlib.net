#pragma once
#include "..\fstlib\interface\ifstcolumn.h"

namespace Fst
{
	public enum class FstColumnScale
	{
		Pico = SCALE_PICO,
		Nano = SCALE_NANO,
		Micro = SCALE_MICRO,
		Milli = SCALE_MILLI,
		Unity = SCALE_UNITY,
		Kilo = SCALE_KILO,
		Mega = SCALE_MEGA,
		Giga = SCALE_GIGA,
		Tera = SCALE_TERA
	};
}