#include "oot.h"
#include "Util.h"

namespace oot {	namespace util {

std::tstring trim( std::tstring& str )
{
	if(str.size() == std::tstring::npos)
		return _T("");

	std::tstring::size_type beginIdx = str.find_first_not_of(' ', 0);
	std::tstring::size_type endIdx = str.find_last_not_of(' ', 0);

	if( beginIdx == 0 && endIdx == 0 )
		return _T("");

	return str.substr(beginIdx, str.size() - endIdx);

}

std::tstring combine( std::vector<std::tstring>& strs, const std::tstring& delimiter )
{
	std::tstring ret(_T(""));
	std::vector<std::tstring>::iterator iter = strs.begin();

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

std::vector<std::tstring> split( std::tstring& str, const std::tstring& delimiter )
{
	using std::tstring;
	std::vector<tstring> tokens;

	tstring::size_type lastPos = str.find_first_not_of(delimiter, 0);
	tstring::size_type pos     = str.find_first_of(delimiter, lastPos);

	while (tstring::npos != pos || tstring::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiter, pos);
		pos = str.find_first_of(delimiter, lastPos);
	}

	return tokens;
}

}} /* namespace oot::util */