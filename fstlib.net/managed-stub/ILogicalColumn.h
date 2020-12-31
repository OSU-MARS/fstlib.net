#pragma once
using namespace System;

namespace Fst
{
	public interface class ILogicalColumn
	{
	public:
		// void Annotate(String annotation); // why no annotate?

		property array<int>^ Data
		{
			array<int>^ get();
		}
	};
}