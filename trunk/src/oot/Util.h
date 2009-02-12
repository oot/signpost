#pragma once

#include <string>

namespace oot {	namespace util {

	std::wstring MbsToWcs(const std::string& str);
	std::string WcsToMbs(const std::wstring& str);

	std::wstring AlwaysToWcs(const std::string& str);
	std::wstring AlwaysToWcs(const std::wstring& str);
	std::string AlwaysToMbs(const std::string& str);
	std::string AlwaysToMbs(const std::wstring& str);

}}