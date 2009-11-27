#pragma once

#include <gtkmm.h>

class WindowPreview : public Gtk::ScrolledWindow
{
public:
	WindowPreview(void);
	~WindowPreview(void);


private:
	Gtk::TextView	  tviewItem;
};
