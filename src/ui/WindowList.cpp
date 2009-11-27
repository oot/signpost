#include "oot.h"
#include "WindowList.h"

WindowList::WindowList(void)
: lviewTextItem(0, true, Gtk::SELECTION_SINGLE)
{
	add(lviewTextItem);

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowList::~WindowList(void)
{
}
