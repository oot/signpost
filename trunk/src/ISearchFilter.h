#pragma once

class ISearchFilter
{
public:
	ISearchFilter(void);
	virtual ~ISearchFilter(void);

	virtual void getStartDate() = 0;
	virtual void getEndDate() = 0;

	virtual void getTags() = 0;

	virtual void getCategories() = 0;

	virtual std::tstring getSql() = 0;


};
