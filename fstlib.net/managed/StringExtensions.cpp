#include "pch.h"
#include <msclr/marshal_cppstd.h> // include before StringExtensions.h to avoid build errors on ::IServiceProvider and System::IServiceProvider conflict

#include "StringExtensions.h"


namespace Fst
{
	// wrapper method since #including marshal_cppstd.h includes typedef BYTE, conflicting with ::FstColumnType::BYTE 
	std::string StringExtensions::ToNative(String^ str)
	{
		return msclr::interop::marshal_as<std::string>(str);
	}
}