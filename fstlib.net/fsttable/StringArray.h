#pragma once
#include <string>
#include <vector>
#include <interface/ifsttable.h>

class StringArray : public IStringArray
{
	std::vector<std::string>* strVec = nullptr;
	StringEncoding string_encoding;
	bool external = true;

public:
	StringArray() {	}

	StringArray(std::vector<std::string>& strVector)
	{
		SetArray(strVector);
	}

	~StringArray()
	{
		if (!external)
		{
			delete strVec;
		}
	}

	std::string GetStringElement(unsigned int index)
	{
		return strVec->at(index);
	}

	void SetArray(std::vector<std::string>& strVector)
	{
		if (!external)
		{
			delete strVec;
		}
		external = true;
		strVec = &strVector;
	}

	void AllocateArray(unsigned int vecLength)
	{
		if (!external)
		{
			delete strVec;
		}
		external = false;
		strVec = new std::vector<std::string>(vecLength);
	}

	void SetElement(unsigned int elementNr, const char* str)
	{
		std::string strElem(str);
		(*strVec)[elementNr] = strElem;
	}

	void SetElement(unsigned int elementNr, const char* str, unsigned int strLen)
	{
		std::string strElem(str, strLen);
		(*strVec)[elementNr] = strElem;
	}

	const char* GetElement(unsigned int elementNr)
	{
		return (*strVec)[elementNr].c_str();
	}

	unsigned int Length()
	{
		return (int)strVec->size();
	}

	void SetEncoding(StringEncoding string_encoding)
	{
		this->string_encoding = string_encoding;
	}
};
