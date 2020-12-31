#pragma once
using namespace System;

namespace Fst
{
	public interface class IDoubleColumn
	{
	public:
		void Annotate(String^ annotation);

		property array<double>^ Data
		{
			array<double>^ get();
		}
	};
}