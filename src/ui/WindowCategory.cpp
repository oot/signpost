#include "oot.h"
#include "WindowCategory.h"

WindowCategory::WindowCategory(void)
{
	add(categoryListView_);

	categoryListStoreRef_ = CategoryListStore::create(categoryListColumns_);
	categoryListView_.set_model(categoryListStoreRef_);

	//////////////////////////////////////////////////////////////////////////
	//Fill the TreeView's model
	Gtk::TreeModel::Row row = *(categoryListStoreRef_->append());
	row[categoryListColumns_.isSelected] = false;
	row[categoryListColumns_.categoryName] = "Text";

	row = *(categoryListStoreRef_->append());
	row[categoryListColumns_.isSelected] = true;
	row[categoryListColumns_.categoryName] = "Picture";

	row = *(categoryListStoreRef_->append());
	row[categoryListColumns_.isSelected] = false;
	row[categoryListColumns_.categoryName] = "Documents";
	//////////////////////////////////////////////////////////////////////////
/*

	Gtk::CellRendererToggle* cell = Gtk::manage(new Gtk::CellRendererToggle);

	int cols_count = categoryListView_.append_column("isSelected", *cell);

	Gtk::TreeViewColumn* pColumn = categoryListView_.get_column(cols_count - 1);
	if(pColumn)
	{
		//pColumn->add_attribute(cell->property_value(), categoryListColumns_.isSelected);
		pColumn->add_attribute(*cell, "value", categoryListColumns_.isSelected);
	}
	categoryListView_.append_column("Category", categoryListColumns_.categoryName);
	*/


	categoryListView_.append_column_editable("Select", categoryListColumns_.isSelected);
	categoryListView_.append_column("Category", categoryListColumns_.categoryName);

	//////////////////////////////////////////////////////////////////////////

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowCategory::~WindowCategory(void)
{
}
