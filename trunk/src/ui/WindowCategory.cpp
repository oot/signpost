#include "oot.h"
#include "WindowCategory.h"

WindowCategory::WindowCategory(void)
: lvText_(0)
{
	add(lvText_);

	lStore_ = LStoreCategory::create(cols_);
	lvText_.set_model(lStore_);

	//////////////////////////////////////////////////////////////////////////
	//Fill the TreeView's model
	Gtk::TreeModel::Row row = *(lStore_->append());
	row[cols_.isSelected] = false;
	row[cols_.name] = "Text";
	row[cols_.item] = Item::Text;

	row = *(lStore_->append());
	row[cols_.isSelected] = false;
	row[cols_.name] = "Picture";
	row[cols_.item] = Item::Picture;

	row = *(lStore_->append());
	row[cols_.isSelected] = false;
	row[cols_.name] = "Documents";
	row[cols_.item] = Item::Document;
	//////////////////////////////////////////////////////////////////////////

 	lvText_.append_column_editable("!", cols_.isSelected);
 	lvText_.append_column("Category", cols_.name);

	lStore_->signal_row_changed().connect(
							sigc::mem_fun(*this, &WindowCategory::onRowChanged)
							);

	//////////////////////////////////////////////////////////////////////////

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowCategory::~WindowCategory(void)
{
}

ConnectionType WindowCategory::changeHandler( SignalIntType::slot_function_type func )
{
	return signal_.connect(func);
}

void WindowCategory::onRowChanged( const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it )
{
	Gtk::TreeRow row = (*it);
	if(row)
	{
		Item::Type itemType = row[cols_.item];
		signal_(itemType);
	}

}