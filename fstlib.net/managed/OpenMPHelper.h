#pragma once
#include "..\fstlib\interface\openmphelper.h"

namespace Fst
{
	public ref class OpenMPHelper abstract sealed
	{
	public:
		/// <summary>
		/// Return the currently active thread in an OpenMP construct.
		/// </summary>
		/// <returns>ID of the currently active thread.</returns>
		property static int CurrentFstThreadID
		{
			int get()
			{
				return ::CurrentFstThread();
			}
		}

		/// <summary>
		/// Check if the C++ FstLib is compiled with OpenMP.
		/// </summary>
		property static bool HasOpenMP
		{
			bool get()
			{
				return ::HasOpenMP();
			}
		}

		/// <summary>
		/// Get or set the number of threads without querying the current number of threads used.
		/// Use this property instead of ThreadsFst when calling from a fork.
		/// </summary>
		property static int Threads
		{
			int get()
			{
				return ::GetThreads();
			}
			void set(int threadCount)
			{
				::SetThreads(threadCount);
			}
		}

		/// <summary>
		/// Get or set the number of threads used in parallel computations.
		/// </summary>
		property static int FstThreads
		{
			int get()
			{
				return ::GetFstThreads();
			}
			void set(int threadCount)
			{
				::ThreadsFst(threadCount);
			}
		}
	};
}