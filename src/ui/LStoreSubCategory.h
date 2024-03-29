#pragma once

#include <gtkmm.h>

class SubCategoryColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	SubCategoryColumns() {
		add(isSelected);
		add(icon);
		add(type);
		add(name);
	};

	Gtk::TreeModelColumn<bool> isSelected;
	Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf> > icon;
	Gtk::TreeModelColumn<int> type;
	Gtk::TreeModelColumn<std::string> name;
};

class LStoreSubCategory : public Gtk::ListStore
{
public:
	LStoreSubCategory(void);
	~LStoreSubCategory(void);

	void update();
};
