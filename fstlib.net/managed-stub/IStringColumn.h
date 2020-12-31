#pragma once
using namespace System;

namespace Fst
{
	public interface class IStringColumn
	{
	public:
		void AllocateVec(int length);
		void BufferToVec(int count, int start, int end, int offset, int^ sizeMeta, String^ buf);

		property String^ default[int]
		{
			String^ get(int index);
		}

		property StringEncoding Encoding
		{
			StringEncoding get();
			void set(StringEncoding value);
		}
	};
}