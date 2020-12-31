#pragma once
#include "StringEncoding.h"
using namespace System;

namespace Fst
{
    public interface class IStringWriter
    {
    public:
        property array<Byte>^ ActiveBuf
        {
            array<Byte>^ get();
        }

        property array<int>^ BufferSize
        {
            array<int>^ get();
        }

        property StringEncoding Encoding
        {
            StringEncoding get();
        }

        property array<int>^ NAInts
        {
            array<int>^ get();
        }

        property array<UInt32>^ StringSizes
        {
            array<UInt32>^ get();
        }

        property int VectorLength
        {
            int get();
        }

        void SetBuffersFromVec(unsigned long long startCount, unsigned long long endCount);
    };
}

