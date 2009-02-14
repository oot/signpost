#include "oot.h"
#include "CategoryListStore.h"

CategoryListStore::CategoryListStore(void)
: Gtk::ListStore(columns)
{
	//basicInfo.open();
	//basicInfo.initialize();
}

CategoryListStore::~CategoryListStore(void)
{
}

void CategoryListStore::update()
{
	//basicInfo.updateCategoryFromDb();

	this->clear();
	Gtk::TreeModel::Row row = *(this->append());
	row[columns.isSelected] = false;
	row[columns.categoryName] = "Text";

	row = *(this->append());
	row[columns.isSelected] = true;
	row[columns.categoryName] = "Picture";

	row = *(this->append());
	row[columns.isSelected] = false;
	row[columns.categoryName] = "Documents";
}