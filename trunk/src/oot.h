#ifndef __OOT_H__
#define __OOT_H__

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#endif

#include <string>

#ifndef _T
#ifdef _UNICODE
#define _T(x)	L ## x
#else
#define _T(x)	x
#endif
#endif

#ifndef __STD_TSTRING__
#define __STD_TSTRING__

namespace std
{
#ifdef _UNICODE
	typedef wchar_t tchar_t;
#else
	typedef char tchar_t;
#endif
	typedef basic_string<tchar_t> tstring;
}

namespace std
{
	typedef basic_ios<tchar_t>              tios;
	typedef basic_streambuf<tchar_t>        tstreambuf;
	typedef basic_istream<tchar_t>          tistream;
	typedef basic_ostream<tchar_t>          tostream;
	typedef basic_iostream<tchar_t>         tiostream;
	typedef basic_stringbuf<tchar_t>        tstringbuf;
	typedef basic_istringstream<tchar_t>    tistringstream;
	typedef basic_ostringstream<tchar_t>    tostringstream;
	typedef basic_stringstream<tchar_t>     tstringstream;
	typedef basic_filebuf<tchar_t>          tfilebuf;
	typedef basic_ifstream<tchar_t>         tifstream;
	typedef basic_ofstream<tchar_t>         tofstream;
	typedef basic_fstream<tchar_t>          tfstream;
}

#endif




#include <cstdio>
#include <gtkmm.h>



#endif /* __OOT_H__ */
