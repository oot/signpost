#pragma once

#include <gtkmm.h>

#include "Text.h"
#include "LstoreItemList.h"

#include "BoostTypes.h"

class WindowList : public Gtk::ScrolledWindow
{
public:
	WindowList(void);
	~WindowList(void);

public:
	void setItemData(std::vector<Text> txts);

	ConnectionType registerHander(SignalUIntType::slot_function_type func);

private:
	void onRowChanged(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it);
	void onRowActivated(const Gtk::TreeModel::Path& path, const Gtk::TreeViewColumn* column);

private:
	ItemListColumns cols_;
	Gtk::ListViewText lvText_;
	Glib::RefPtr<Gtk::ListStore> lstore_;

	SignalUIntType sinalRowActivated_;
};
