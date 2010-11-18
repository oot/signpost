#pragma once

#include <gtkmm.h>
#include "Item.h"

class ItemListColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	ItemListColumns() {
		add(title);
		add(itemType);
		add(id);
	};

	Gtk::TreeModelColumn<std::string> title;
	Gtk::TreeModelColumn<int> itemType;
	Gtk::TreeModelColumn<unsigned> id;

};

class LstoreItemList : public Gtk::ListStore
{
public:
	LstoreItemList(void);
	~LstoreItemList(void);

	void update();
};
