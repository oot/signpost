#include "oot.h"
#include "Util.h"

#include <windows.h> // GetModuleFileName
#include <direct.h> // _mkdir
#include <sys/timeb.h> // _timeb

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

std::vector<std::string> split( const std::string& str, const std::string& delimiter )
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

std::vector<std::wstring> split( const std::wstring& str, const std::wstring& delimiter )
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

std::string getProgramPath( bool isDirOnly /*= true*/ )
{
	char szBuffer[MAX_PATH];
	std::string strRet;
	::GetModuleFileNameA(NULL, szBuffer, MAX_PATH);
	strRet = szBuffer;

	if(!isDirOnly)
		return strRet;

	int nIndex = strRet.find_last_of('\\');
	return strRet.substr(0, nIndex);
}

bool makeDir( const std::string& path )
{
	std::vector<std::string> dirs = split(path, "\\");

	if(dirs.empty()) return false;

	std::string dir;

	unsigned i;
	for(i = 0; i < (dirs.size() - 1); i++)
	{
		if(i == 0) dir = dirs[i];
		else dir.append("\\" + dirs[i]);

		int ret = _mkdir(dir.c_str());
	}

	if(i == 0) dir = dirs[i];
	else dir.append("\\" + dirs[i]);

	int ret = _mkdir(dir.c_str());

	if(ret) return false;
	else return true;
}

std::string getCurrentDateTime()
{
	_timeb tb;
	_ftime_s(&tb);

	struct tm t;
	localtime_s(&t, &tb.time);

	char datetime[100] = { '\0' };
	sprintf_s(datetime, 100, "%04d%02d%02dT%02d%02d%02d.%03d", 
			t.tm_year + 1900,
			t.tm_mon + 1,
			t.tm_mday,
			t.tm_hour,
			t.tm_min,
			t.tm_sec,
			tb.millitm );

	std::string datetimeStr(datetime);

	return datetimeStr;
}

bool existDir( const string& path )
{
	if(_chdir(path.c_str())) return false;

	return true;
}

}} /* namespace oot::util */
