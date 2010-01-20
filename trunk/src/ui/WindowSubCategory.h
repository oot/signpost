#pragma once

#include <gtkmm.h>
#include "LStoreSubCategory.h"
#include "Item.h"
#include "BoostTypes.h"

class CategorySelect
{
public:
	std::string category;
	Item::Type type;
	bool isSelected;
};

typedef boost::signal<void(CategorySelect)> SignalCategorySelectType;

class WindowSubCategory : public Gtk::ScrolledWindow
{
public:
	WindowSubCategory(void);
	~WindowSubCategory(void);

	ConnectionType changeHandler(SignalCategorySelectType::slot_function_type func);
	void setData(std::map<Item::Type, std::vector<std::string> >& datas);

private:
	SubCategoryColumns cols_;
	Gtk::ListViewText lvText_;
	Glib::RefPtr<Gtk::ListStore> lStore_;

//	SignalIntType signal_;
	SignalCategorySelectType signal_;


private:

	void onRowChanged(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it);

};
