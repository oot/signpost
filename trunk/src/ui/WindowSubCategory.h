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

	const CategorySelect& operator=( const CategorySelect& rhs )
	{
		if (this != &rhs)
		{
			this->category = rhs.category;
			this->type = rhs.type;
			this->isSelected = rhs.isSelected;
		}
		return *this; 
	}

	const bool operator==( const CategorySelect& rhs )
	{

		if(this->category == rhs.category && this->type == rhs.type) return true;
		else return false;
	}
};

typedef boost::signal<void(CategorySelect)> SignalCategorySelectType;
typedef boost::signal<void(vector<CategorySelect>&)> SignalCategoriesSelectType;

class WindowSubCategory : public Gtk::VBox
{
public:
	WindowSubCategory(void);
	~WindowSubCategory(void);

	ConnectionType changeHandler(SignalCategoriesSelectType::slot_function_type func);
	void setData(std::map<Item::Type, std::vector<std::string> >& datas);

private:
	Gtk::Toolbar toolbar_;
	Gtk::ToolButton tbuttonNew_;
	Gtk::ToolButton tbuttonDelete_;
	Gtk::VBox vbox_;
	Gtk::ScrolledWindow sWindow_;
	SubCategoryColumns cols_;
	Gtk::ListViewText lvText_;
	Glib::RefPtr<Gtk::ListStore> lStore_;

//	SignalIntType signal_;
	SignalCategoriesSelectType signal_;
	vector<CategorySelect> selectedItems_;


private:

	void onRowChanged(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it);

	void onButtonNew();
	void onButtonDelete();
};
