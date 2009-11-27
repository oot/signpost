#include "oot.h"
#include "Item.h"

Item::Item(void)
{
}

Item::~Item(void)
{
}

void Item::getTags( Tags* tags )
{
	tags->clear();

	for(int i = 0; tags_.getCount() < i; i++)
	{
		tags->add(tags_.get(i));	
	}
}

