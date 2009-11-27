#pragma once

#include <gtkmm.h>

class WindowList : public Gtk::ScrolledWindow
{
public:
	WindowList(void);
	~WindowList(void);


private:
	Gtk::ListViewText lviewTextItem;
};
