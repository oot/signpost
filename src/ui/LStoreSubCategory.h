#pragma once

#include <gtkmm.h>

class SubCategoryColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	SubCategoryColumns() {
		add(isSelected);
		add(icon);
		add(name);
	};

	Gtk::TreeModelColumn<bool> isSelected;
	Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf> > icon; 
	Gtk::TreeModelColumn<Glib::ustring> name;

};

class LStoreSubCategory : public Gtk::ListStore
{
public:
	LStoreSubCategory(void);
	~LStoreSubCategory(void);

	void update();

	SubCategoryColumns columns;

};
