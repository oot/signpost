#pragma once

class ISearchCondition
{
public:
	ISearchCondition(void);
	virtual ~ISearchCondition(void);

	virtual void getStartDate() = 0;
	virtual void getEndDate() = 0;

	virtual void getTags() = 0;

	virtual void getCategories() = 0;


};
