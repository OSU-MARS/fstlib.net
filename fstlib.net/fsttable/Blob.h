#pragma once

class Blob
{
	unsigned char* pData = nullptr;

public:
	Blob(unsigned long long size)
	{
		pData = new unsigned char[size];
	}

	unsigned char* Data()
	{
		return pData;
	}

	~Blob()
	{
		delete[] pData;
	}
};
