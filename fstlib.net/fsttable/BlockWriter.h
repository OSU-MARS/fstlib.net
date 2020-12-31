#pragma once
#include <string>
#include <vector>
#include <interface/ifsttable.h>
#include <interface/fstdefines.h>

class BlockWriter : public IStringWriter
{
	std::vector<std::string>* strVecP;

public:
	// Stack buffers
	unsigned int naIntsBuf[1 + BLOCKSIZE_CHAR / 32];  // we have 32 NA bits per integer
	unsigned int strSizesBuf[BLOCKSIZE_CHAR];  // we have 32 NA bits per integer
	char strBuf[MAX_CHAR_STACK_SIZE];

	// Heap buffer
	unsigned int heapBufSize = BASIC_HEAP_SIZE;
	char* heapBuf = new char[BASIC_HEAP_SIZE];

	BlockWriter(std::vector<std::string>& strVec)
	{
		strVecP = &strVec;

		this->naInts = naIntsBuf;
		this->strSizes = strSizesBuf;
		this->vecLength = static_cast<unsigned int>(strVec.size());
	}

	~BlockWriter() { delete[] heapBuf; }

	void SetBuffersFromVec(unsigned long long startCount, unsigned long long endCount)
	{
		// Determine string lengths
		// unsigned int startCount = block * BLOCKSIZE_CHAR;
		unsigned long long nrOfElements = endCount - startCount;  // the string at position endCount is not included
		unsigned long long nrOfNAInts = 1 + nrOfElements / 32;  // add 1 bit for NA present flag

		unsigned int totSize = 0;
		//unsigned int hasNA = 0;
		int sizeCount = -1;

		memset(naInts, 0, nrOfNAInts * 4);  // clear NA bit metadata block (neccessary?)

		for (unsigned long long count = startCount; count != endCount; ++count)
		{
			std::string strElem = (*strVecP)[count];

			// Skip NA string concept for now
			//if (strElem == NA_STRING)  // set NA bit
			//{
			//	++hasNA;
			//	unsigned int intPos = (count - startCount) / 32;
			//	unsigned int bitPos = (count - startCount) % 32;
			//	naInts[intPos] |= 1 << bitPos;
			//}

			totSize += static_cast<unsigned int>(strElem.size());
			strSizes[++sizeCount] = totSize;
		}

		// Skip NA string concept for now
		//if (hasNA != 0)  // NA's present in vector
		//{
		//	// set last bit
		//	int bitPos = nrOfElements % 32;
		//	naInts[nrOfNAInts - 1] |= 1 << bitPos;
		//}


		// Write string data
		sizeCount = -1;
		this->activeBuf = strBuf;

		if (totSize > MAX_CHAR_STACK_SIZE)  // don't use cache memory
		{
			if (totSize > heapBufSize)
			{
				delete[] heapBuf;
				heapBufSize = (unsigned int)(totSize * 1.1);
				heapBuf = new char[heapBufSize];
			}

			this->activeBuf = heapBuf;
		}

		size_t lastPos = 0;
		for (unsigned long long count = startCount; count < endCount; ++count)
		{
			const char* str = (*strVecP)[count].c_str();
			size_t pos = strSizes[++sizeCount];
			// C4996: strncpy(this->activeBuf + lastPos, str, pos - lastPos);
			strncpy_s(this->activeBuf + lastPos, MAX_CHAR_STACK_SIZE, str, pos - lastPos);
			lastPos = pos;
		}

		bufSize = totSize;
	}

	StringEncoding Encoding()
	{
		return StringEncoding::LATIN1;
	}
};
