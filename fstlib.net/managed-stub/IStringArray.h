#pragma once
using namespace System;

namespace Fst
{
	public interface class IStringArray
	{
	public:
		void AllocateArray(int length);
		
		property String^ default[int]
		{
			String^ get(int index);
			void set(int index, String^ value);
		}
		
		// void SetEncoding(StringEncoding encoding); // no get accessor?
		property StringEncoding Encoding
		{
			void set(StringEncoding encoding);
		}

		property int Length
		{
			int get();
		}
	};
}