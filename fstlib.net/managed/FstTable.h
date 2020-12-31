#pragma once
#include "FstColumn.h"

#include "../fsttable/FstTable.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace Fst
{
	public ref class FstTable
	{
	private:
		List<FstColumn^>^ columns;

	public:
		property List<FstColumn^>^ Columns
		{
			List<FstColumn^>^ get() { return this->columns; }
		}

		FstTable();

		/// <summary>
		/// Write table to a file.
		/// </summary>
		/// <param name="filePath">Name of file to create or overwrite.</param>
		/// <param name="compress">Compression factor with a value 0 - 100.</param>
		void Write(String^ filePath, int compressionFactor);
	};
}