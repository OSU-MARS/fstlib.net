#pragma once
#include "IStringColumn.h"
using namespace System;

namespace Fst
{
	public interface class IFactorColumn
	{
	public:
		property array<int>^ Data
		{
			array<int>^ get();
		}

		property IStringColumn^ Levels
		{
			IStringColumn^ get();
		}
	};
}