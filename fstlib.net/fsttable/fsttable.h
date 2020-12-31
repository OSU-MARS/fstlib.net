#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <interface/ifsttable.h>
#include <interface/fstdefines.h>

#include "BlockWriter.h"
#include "ByteVector.h"
#include "ByteVectorAdapter.h"
#include "DestructableObject.h"
#include "DoubleVector.h"
#include "DoubleVectorAdapter.h"
#include "FactorVector.h"
#include "FactorVectorAdapter.h"
#include "IntVector.h"
#include "IntVectorAdapter.h"
#include "Int64VectorAdapter.h"
#include "LogicalVectorAdapter.h"
#include "LongVector.h"
#include "StringArray.h"
#include "StringColumn.h"

class FstTable : public IFstTable
{
	std::vector<std::shared_ptr<DestructableObject>>* columns = nullptr;
	std::vector<FstColumnType>* columnTypes = nullptr;
	std::vector<FstColumnAttribute>* columnAttributes = nullptr;
	std::vector<std::string>* colAnnotations = nullptr;
	std::vector<std::string>* colNames = nullptr;
	std::vector<short int>* colScales = nullptr;
	unsigned long long nrOfRows;

public:
	FstTable()
	{
		this->nrOfRows = 0;
	}

	FstTable(unsigned long long nrOfRows)
	{
		this->nrOfRows = nrOfRows;
	}

	~FstTable()
	{
		delete this->columnTypes;
		delete this->colNames;
		delete this->columns;
		delete this->columnAttributes;
		delete this->colAnnotations;
		delete this->colScales;
	}

	FstTable* SubSet(std::vector<std::string>& columnNames, unsigned long long startRow, unsigned long long endRow) const
	{
		FstTable* subset = new FstTable();
		subset->InitTable(static_cast<unsigned int>(columnNames.size()), 1 + endRow - startRow);

		int subSetColNr = 0;
		for (std::vector<std::string>::iterator colIt = columnNames.begin(); colIt != columnNames.end(); ++colIt)
		{
			auto it = std::find(colNames->begin(), colNames->end(), *colIt);
			int index;

			// Search column
			if (it == colNames->end())
			{
				// name not in vector
				throw("Unknown column");
			}
			else
			{
				index = static_cast<int>(it - colNames->begin());
			}

			// Copy smart pointers to columns
			subset->SetColumn((*columns)[index], subSetColNr, (*columnTypes)[index], (*columnAttributes)[index], (*colNames)[index],
				(*colScales)[index], (*colAnnotations)[index]);
			subSetColNr++;
		}

		return subset;
	}

	void GetColumn(int colNr, std::shared_ptr<DestructableObject>& column, FstColumnType& type, std::string& colName,
		short int& colScale, std::string& colAnnotation) const
	{
		column = (*columns)[colNr];
		type = (*columnTypes)[colNr];
		colName = (*colNames)[colNr];
		colAnnotation = (*colAnnotations)[colNr];
		colScale = (*colScales)[colNr];
	}

	void SetColumn(std::shared_ptr<DestructableObject> column, int colNr, FstColumnType type, FstColumnAttribute attribute, std::string colName,
		short int scale, std::string annotation) const
	{
		(*columns)[colNr] = column;
		(*columnTypes)[colNr] = type;
		(*columnAttributes)[colNr] = attribute;
		(*colNames)[colNr] = colName;
		(*colAnnotations)[colNr] = annotation;
		(*colScales)[colNr] = scale;
	}

	std::vector<std::string>* ColumnNames()
	{
		return this->colNames;
	}

	void SetColumnNames(StringArray& colnames) const
	{
		for (int colNr = 0; colNr < this->colNames->size(); colNr++)
		{
			(*colNames)[colNr] = colnames.GetElement(colNr);
		}
	}

	void SetColumnNames(std::vector<std::string> colNameVec) const
	{
		int colNr = 0;
		for (std::vector<std::string>::iterator colNameIt = colNameVec.begin(); colNameIt != colNameVec.end(); ++colNameIt)
		{
			(*colNames)[colNr++] = colNameIt->c_str();
		}
	}

	void InitTable(unsigned int nrOfCols, unsigned long long nrOfRows)
	{
		if (this->columns != nullptr)
		{
			throw(std::runtime_error("InitTable called multiple times!"));
		}

		this->nrOfRows = nrOfRows;

		this->columns = new std::vector<std::shared_ptr<DestructableObject>>(nrOfCols);
		this->columnTypes = new std::vector<FstColumnType>(nrOfCols);
		this->columnAttributes = new std::vector<FstColumnAttribute>(nrOfCols);
		this->colNames = new std::vector<std::string>(nrOfCols);
		this->colAnnotations = new std::vector<std::string>(nrOfCols);
		this->colScales = new std::vector<short int>(nrOfCols);
	}

	void SetStringColumn(IStringColumn* stringColumn, int colNr)
	{
		StringColumn* strCol = static_cast<StringColumn*>(stringColumn);
		(*columns)[colNr] = strCol->StrVector();
		(*columnTypes)[colNr] = FstColumnType::CHARACTER;
	}

	void SetIntegerColumn(IIntegerColumn* integerColumn, int colNr)
	{
		IntVectorAdapter* intAdapter = (IntVectorAdapter*)integerColumn;
		(*columns)[colNr] = intAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::INT_32;
		(*columnAttributes)[colNr] = intAdapter->Attribute();
		(*colScales)[colNr] = intAdapter->Scale();
	}

	void SetIntegerColumn(IIntegerColumn* integerColumn, int colNr, std::string& annotation)
	{
		IntVectorAdapter* intAdapter = (IntVectorAdapter*)integerColumn;
		(*columns)[colNr] = intAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::INT_32;
		(*columnAttributes)[colNr] = intAdapter->Attribute();
		(*colAnnotations)[colNr] = annotation;
		(*colScales)[colNr] = intAdapter->Scale();
	}

	void SetByteColumn(IByteColumn* byteColumn, int colNr)
	{
		ByteVectorAdapter* byteAdapter = (ByteVectorAdapter*)byteColumn;
		(*columns)[colNr] = byteAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::BYTE;
	}

	void SetLogicalColumn(ILogicalColumn* logicalColumn, int colNr)
	{
		LogicalVectorAdapter* logicalAdapter = (LogicalVectorAdapter*)logicalColumn;
		(*columns)[colNr] = logicalAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::BOOL_2;
	}

	void SetInt64Column(IInt64Column* int64Column, int colNr)
	{
		Int64VectorAdapter* int64Adapter = (Int64VectorAdapter*)int64Column;
		(*columns)[colNr] = int64Adapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::INT_64;
		(*columnAttributes)[colNr] = int64Adapter->ColumnAttribute();
	}

	void SetDoubleColumn(IDoubleColumn* doubleColumn, int colNr, std::string& annotation)
	{
		DoubleVectorAdapter* doubleAdapter = (DoubleVectorAdapter*)doubleColumn;
		(*columns)[colNr] = doubleAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::DOUBLE_64;
		(*colAnnotations)[colNr] = annotation;
	}

	void SetDoubleColumn(IDoubleColumn* doubleColumn, int colNr)
	{
		DoubleVectorAdapter* doubleAdapter = (DoubleVectorAdapter*)doubleColumn;
		(*columns)[colNr] = doubleAdapter->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::DOUBLE_64;
	}

	void SetFactorColumn(IFactorColumn* factorColumn, int colNr)
	{
		FactorVectorAdapter* factColumn = static_cast<FactorVectorAdapter*>(factorColumn);
		(*columns)[colNr] = factColumn->DataPtr();
		(*columnTypes)[colNr] = FstColumnType::FACTOR;
	}

	void SetKeyColumns(int* keyColPos, unsigned int nrOfKeys)
	{
	}

	FstColumnType ColumnType(unsigned int colNr, FstColumnAttribute& columnAttribute, short int& scale, std::string& annotation, bool& hasAnnotation)
	{
		columnAttribute = (*columnAttributes)[colNr];
		annotation += (*colAnnotations)[colNr];
		scale = (*colScales)[colNr];
		hasAnnotation = false;

		return (*columnTypes)[colNr];
	}

	IStringWriter* GetStringWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		StringVector* strVec = static_cast<StringVector*>(&(*sp));
		std::vector<std::string>* strVecP = strVec->StrVec();
		return new BlockWriter(*strVecP);
	}

	int* GetLogicalWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		IntVector* intVec = static_cast<IntVector*>(&(*sp));
		return intVec->Data();
	}

	int* GetIntWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		IntVector* intVec = static_cast<IntVector*>(&(*sp));
		return intVec->Data();
	}

	char* GetByteWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		ByteVector* byteVec = static_cast<ByteVector*>(&(*sp));
		return byteVec->Data();
	}

	int* GetDateTimeWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		IntVector* intVec = static_cast<IntVector*>(&(*sp));
		return intVec->Data();
	}

	long long* GetInt64Writer(unsigned int colNr)
	{
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		LongVector* int64Vec = static_cast<LongVector*>(&(*sp));
		return int64Vec->Data();
	}


	double* GetDoubleWriter(unsigned int colNr)
	{
		// TODO: Add colType checker
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		DoubleVector* dblVec = static_cast<DoubleVector*>(&(*sp));
		return dblVec->Data();
	}

	IStringWriter* GetLevelWriter(unsigned int colNr)
	{
		// TODO: Add colType checker

		// Get factor vector
		std::shared_ptr<DestructableObject> sp = (*columns)[colNr];
		FactorVector* factorVec = static_cast<FactorVector*>(&(*sp));

		// Get level vector from factor
		StringColumn* strCol = factorVec->Levels();
		std::shared_ptr<DestructableObject> sharedStrP = strCol->StrVector();
		StringVector* strVec = static_cast<StringVector*>(&(*sharedStrP));

		// Create blockwriter for levels
		std::vector<std::string>* strVecP = strVec->StrVec();
		return new BlockWriter(*strVecP);
	}

	IStringWriter* GetColNameWriter()
	{
		// TODO: Add colType checker
		return new BlockWriter(*colNames);
	}

	void GetKeyColumns(int* keyColPos) {}

	unsigned int NrOfKeys()
	{
		return 0;
	}

	unsigned int NrOfColumns()
	{
		return (unsigned int)columnTypes->size();
	}

	unsigned long long NrOfRows()
	{
		return nrOfRows;
	}

	void SetColNames(IStringArray* col_names)
	{
		for (int colNr = 0; colNr < this->colNames->size(); colNr++)
		{
			(*colNames)[colNr] = col_names->GetElement(colNr);
		}
	}
};