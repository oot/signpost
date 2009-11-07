#include "oot.h"
#include "LStoreSubCategory.h"

LStoreSubCategory::LStoreSubCategory(void)
: Gtk::ListStore(columns)
{

}

LStoreSubCategory::~LStoreSubCategory(void)
{
}

void LStoreSubCategory::update()
{
	//render_icon(4, Gtk::ICON_SIZE_MENU);
	this->clear();
	Gtk::TreeModel::Row row = *(this->append());
	row[columns.isSelected] = false;
	//row[columns.icon] =  render_icon(4, Gtk::ICON_SIZE_MENU);
	row[columns.name] = "test1";

	Gtk::StockID stockid;

	Gtk::StockItem stockItem;
	//stockItem.lookup(stockid,)
}