#pragma once

#include <gtkmm.h>
#include "x/CategoryListView.h"
#include "x/CategoryListStore.h"

class WindowCategory : public Gtk::ScrolledWindow
{
public:
	WindowCategory(void);
	~WindowCategory(void);


private:
	CategoryColumns categoryListColumns_;
	CategoryListView categoryListView_;
	Glib::RefPtr<Gtk::ListStore> categoryListStoreRef_;
};
