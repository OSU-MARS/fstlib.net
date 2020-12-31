#pragma once
using namespace System;

namespace Fst
{
	public interface class IBlobContainer
	{
		property array<Byte>^ Data
		{
			array<Byte>^ get();
		}
		
		property UInt64 Size
		{
			UInt64 get();
		}
	};
}