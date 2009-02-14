#pragma once

#include <gtkmm.h>
#include "BasicInfo.h"

class CategoryColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	CategoryColumns() {
		add(isSelected);
		add(categoryName);
	};

	Gtk::TreeModelColumn<bool> isSelected;
	Gtk::TreeModelColumn<Glib::ustring> categoryName;

};

class CategoryListStore : public Gtk::ListStore
{
public:
	CategoryListStore(void);
	~CategoryListStore(void);

	void update();

	CategoryColumns columns;

	//BasicInfo basicInfo;
};
