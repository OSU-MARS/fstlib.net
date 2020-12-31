#pragma once
using namespace System;

namespace Fst
{
	public interface class IInt32Column
	{
	public:
		void Annotate(String^ annotation);

		property array<int>^ Data
		{
			array<int>^ get();
		}
	};
}