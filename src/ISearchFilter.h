#ifndef __ISEARCHFILTER_H__
#define __ISEARCHFILTER_H__

#include "oot.h"

class ISearchFilter
{
public:
	ISearchFilter(void);
	virtual ~ISearchFilter(void);

	virtual void getStartDate() = 0;
	virtual void getEndDate() = 0;

	virtual void getTags() = 0;

	virtual void getCategories() = 0;

	virtual std::string getSql() = 0;


};

#endif // __ISEARCHFILTER_H__
