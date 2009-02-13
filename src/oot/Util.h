#pragma once

#include "oot.h"
#include <string>

namespace oot {	namespace util {

	std::wstring mbsToWcs(const std::string& str);
	std::string wcsToMbs(const std::wstring& str);

	std::wstring alwaysToWcs(const std::string& str);
	std::wstring alwaysToWcs(const std::wstring& str);
	std::string alwaysToMbs(const std::string& str);
	std::string alwaysToMbs(const std::wstring& str);

	std::tstring trim( std::tstring& str );
	std::tstring combine( std::vector<std::tstring>& strs, const std::tstring& delimiter );
	std::vector<std::tstring> split( std::tstring& str, const std::tstring& delimiter );

}}