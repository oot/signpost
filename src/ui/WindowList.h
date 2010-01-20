#pragma once

#include <gtkmm.h>

#include "Text.h"
#include "LstoreItemList.h"

class WindowList : public Gtk::ScrolledWindow
{
public:
	WindowList(void);
	~WindowList(void);

public:
	void setItemData(std::vector<Text> txts);

private:
	void onRowChanged(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it);

private:
	ItemListColumns cols_;
	Gtk::ListViewText lvText_;
	Glib::RefPtr<Gtk::ListStore> lstore_;
};
