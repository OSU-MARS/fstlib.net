#pragma once
using namespace System;

namespace Fst
{
	public interface class IByteColumn
	{
	public:
		// void Annotate(String annotation); // why no annotate?

		property array<Byte>^ Data
		{
			array<Byte>^ get();
		}
	};
}