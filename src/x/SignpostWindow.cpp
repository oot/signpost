#include "oot.h"
#include "SignpostWindow.h"

SignpostWindow::SignpostWindow(void)
:itemList_(5),
newToolButton_(Gtk::Stock::NEW),
openMenuItem_("_Open"),
closeMenuItem_("_Close"),
quitMenuItem_("_Quit"),
aboutMenuItem_("_About"),
fileMenuItem_("_File"),
viewMenuItem_("_View"),
helpMenuItem_("_Help")
{
	vbox_.pack_start(menubar_, Gtk::PACK_SHRINK);
	vbox_.pack_start(toolbar_, Gtk::PACK_SHRINK);
	vbox_.add(hpaned_);
	vbox_.pack_start(statusbar_, Gtk::PACK_SHRINK);

	hpaned_.add(categoryScrolledWindow_);
	hpaned_.add(itemScrolledWindows_);
	//hpaned_.add(detailedItemTextView_);

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

	categoryScrolledWindow_.add(categoryListView_);
	categoryScrolledWindow_.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	itemScrolledWindows_.add(itemList_);
	itemScrolledWindows_.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);



	menubar_.add(fileMenuItem_);
	menubar_.add(viewMenuItem_);
	menubar_.add(helpMenuItem_);

	
	toolbar_.append(newToolButton_);

	fileMenu_.append(openMenuItem_);
	fileMenu_.append(closeMenuItem_);
	fileMenu_.append(quitMenuItem_);
	helpMenu_.append(aboutMenuItem_);

	fileMenuItem_.set_submenu(fileMenu_);
	helpMenuItem_.set_submenu(helpMenu_);
	

	add(vbox_);

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

SignpostWindow::~SignpostWindow(void)
{
}
