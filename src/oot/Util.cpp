#include "oot.h"
#include "Util.h"

namespace oot {	namespace util {

std::string trim( std::string& str )
{
	if(str.size() == std::string::npos)
		return "";

	std::string::size_type beginIdx = str.find_first_not_of(' ', 0);
	std::string::size_type endIdx = str.find_last_not_of(' ', 0);

	if( beginIdx == 0 && endIdx == 0 )
		return "";

	return str.substr(beginIdx, str.size() - endIdx);

}

std::wstring trim( std::wstring& str )
{
	if(str.size() == std::wstring::npos)
		return L"";

	std::wstring::size_type beginIdx = str.find_first_not_of(' ', 0);
	std::wstring::size_type endIdx = str.find_last_not_of(' ', 0);

	if( beginIdx == 0 && endIdx == 0 )
		return L"";

	return str.substr(beginIdx, str.size() - endIdx);

}

std::string combine( std::vector<std::string>& strs, const std::string& delimiter )
{
	std::string ret("");
	std::vector<std::string>::iterator iter = strs.begin();

	if( iter == strs.end() ) return ret;

	while( true )
	{
		ret.append( *(iter) );

		iter++;

		if( iter == strs.end() )
			break;

		ret.append(delimiter);
	}

	return ret;
}

std::wstring combine( std::vector<std::wstring>& strs, const std::wstring& delimiter )
{
	std::wstring ret(L"");
	std::vector<std::wstring>::iterator iter = strs.begin();

	if( iter == strs.end() ) return ret;

	while( true )
	{
		ret.append( *(iter) );

		iter++;

		if( iter == strs.end() )
			break;

		ret.append(delimiter);
	}

	return ret;
}

std::vector<std::string> split( std::string& str, const std::string& delimiter )
{
	using std::string;
	std::vector<string> tokens;

	string::size_type lastPos = str.find_first_not_of(delimiter, 0);
	string::size_type pos     = str.find_first_of(delimiter, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiter, pos);
		pos = str.find_first_of(delimiter, lastPos);
	}

	return tokens;
}

std::vector<std::wstring> split( std::wstring& str, const std::wstring& delimiter )
{
	using std::wstring;
	std::vector<wstring> tokens;

	wstring::size_type lastPos = str.find_first_not_of(delimiter, 0);
	wstring::size_type pos     = str.find_first_of(delimiter, lastPos);

	while (wstring::npos != pos || wstring::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiter, pos);
		pos = str.find_first_of(delimiter, lastPos);
	}

	return tokens;
}

}} /* namespace oot::util */
