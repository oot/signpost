#pragma once

#include <gtkmm.h>
#include "Item.h"

class CategoryColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	CategoryColumns() {
		add(isSelected);
		add(name);
		add(item);
	};

	Gtk::TreeModelColumn<bool> isSelected;
	Gtk::TreeModelColumn<std::string> name;
	Gtk::TreeModelColumn<Item::Type> item;

};

class LStoreCategory : public Gtk::ListStore
{
public:
	LStoreCategory(void);
	~LStoreCategory(void);

	void update();
};
