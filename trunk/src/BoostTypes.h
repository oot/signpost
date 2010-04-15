#ifndef __BOOST_TYPES_H__
#define __BOOST_TYPES_H__

#include <boost/signal.hpp>

typedef boost::signals::connection				ConnectionType;

typedef boost::signal<void(void)>				SignalVoidType;
typedef boost::signal<void(int)>				SignalIntType;
typedef boost::signal<void(unsigned)>			SignalUIntType;
typedef boost::signal<void(double)>				SignalDoubleType;
typedef boost::signal<void(const std::string&)>	SignalStringType;

#endif // __BOOST_TYPES_H__
