#pragma once

#include <gtkmm.h>
#include "LStoreCategory.h"
#include "Item.h"
#include "BoostTypes.h"

class WindowCategory : public Gtk::ScrolledWindow
{
public:
	WindowCategory(void);
	~WindowCategory(void);

	ConnectionType changeHandler(SignalIntType::slot_function_type func);

private:
	CategoryColumns cols_;
	Gtk::ListViewText lvText_;
	Glib::RefPtr<Gtk::ListStore> lStore_;

	SignalIntType signal_;

	void onRowChanged(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it);
};
