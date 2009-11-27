#include "oot.h"
#include "Text.h"

Text::Text(void)
{
}

Text::~Text(void)
{
}

DateTimeType Text::getDateTime( View view ) const
{
	return modifiedDate_;
}