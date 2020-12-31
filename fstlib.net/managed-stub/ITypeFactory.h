#pragma once
#include "IBlobContainer.h"

using namespace System;

namespace Fst
{
	public interface class ITypeFactory
	{
		IBlobContainer^ CreateBlobContainer(UInt64 size);
	};
}