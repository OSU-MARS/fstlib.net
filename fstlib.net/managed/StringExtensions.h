#pragma once
#include <string>

using namespace System;
using namespace System::Runtime::CompilerServices;

namespace Fst
{
	[ExtensionAttribute]
	private ref class StringExtensions
	{
	public:
		[ExtensionAttribute]
		static std::string ToNative(System::String^ str);
	};
}

