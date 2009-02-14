#pragma once

#include "Item.h"

class ItemDatabase
{
public:
	ItemDatabase(void);
	virtual ~ItemDatabase(void);

	virtual bool addItem(Item& item) = 0;
	void getItemList();

	void getItem();

};
