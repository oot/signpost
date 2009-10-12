#pragma once

#include "oot.h"
#include <string>
#include <vector>

namespace oot {	namespace util {

	std::wstring mbsToWcs(const std::string& str);
	std::string wcsToMbs(const std::wstring& str);

	std::wstring alwaysToWcs(const std::string& str);
	std::wstring alwaysToWcs(const std::wstring& str);
	std::string alwaysToMbs(const std::string& str);
	std::string alwaysToMbs(const std::wstring& str);

	std::string trim(const std::string& str );
	std::wstring trim(const std::wstring& str );
	std::string combine( std::vector<std::string>& strs, const std::string& delimiter );
	std::wstring combine( std::vector<std::wstring>& strs, const std::wstring& delimiter );
	std::vector<std::string> split( std::string& str, const std::string& delimiter );
	std::vector<std::wstring> split( std::wstring& str, const std::wstring& delimiter );

}}
