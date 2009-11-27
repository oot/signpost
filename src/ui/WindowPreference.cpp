#include "oot.h"
#include "WindowPreference.h"

WindowPreference::WindowPreference(void)
{
	add(hpaned_);

	hpaned_.add1(lvTextItem_);
	hpaned_.add2(winContents_);

	show_all_children();
}

WindowPreference::~WindowPreference(void)
{
}
