#pragma once
using namespace System;

namespace Fst
{
	public interface class IInt64Column
	{
	public:
		// void Annotate(String annotation); // why no annotate?

		property array<Int64>^ Data
		{
			array<Int64>^ get();
		}
	};
}