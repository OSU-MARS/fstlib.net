#pragma once
#include "FstColumnType.h"
using namespace System;

namespace Fst
{
	public ref class FstColumn
	{
	private:
		int length;
		String^ name;
		FstColumnType type;

	public:
		property int Length
		{
			int get() { return this->length; }
			void set(int value) { this->length = value; }
		}
		
		property String^ Name
		{
			String^ get() { return this->Name; }
			void set(String^ value) { this->Name == value; }
		}

		property FstColumnType Type
		{
			FstColumnType get() { return this->type; }
			void set(FstColumnType value) { this->type = value; }
		}
	};
}
