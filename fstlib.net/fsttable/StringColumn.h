#pragma once
#include <memory>

#include <interface/ifsttable.h>
#include "StringVector.h"

class StringColumn : public IStringColumn
{
	std::shared_ptr<StringVector> shared_data;
	StringEncoding string_encoding;

public:
	StringColumn()
	{

	}

	~StringColumn()
	{
	}

	void AllocateVec(unsigned long long vecLength);

	void SetEncoding(StringEncoding stringEncoding)
	{
		this->string_encoding = stringEncoding;
	}

	StringEncoding GetEncoding()
	{
		return string_encoding;
	}

	void BufferToVec(unsigned long long nrOfElements, unsigned long long startElem, unsigned long long endElem, unsigned long long vecOffset,
		unsigned int* sizeMeta, char* buf);

	const char* GetElement(unsigned long long elementNr);

	std::shared_ptr<StringVector> StrVector() const { return shared_data; }
};