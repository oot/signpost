#include "oot.h"
#include "WindowSubCategory.h"

WindowSubCategory::WindowSubCategory(void)
: lvText_(0)
{
	add(lvText_);

	lStore_ = LStoreSubCategory::create(cols_);
	lvText_.set_model(lStore_);
	lvText_.append_column_editable("!", cols_.isSelected);
	lvText_.append_column("icon", cols_.icon);
	lvText_.append_column("name", cols_.name);

	lStore_->signal_row_changed().connect(
		sigc::mem_fun(*this, &WindowSubCategory::onRowChanged)
		);

	//////////////////////////////////////////////////////////////////////////

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowSubCategory::~WindowSubCategory(void)
{
}

void WindowSubCategory::onRowChanged( const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it )
{
	Gtk::TreeRow row = (*it);
	if(row)
	{
		string category = row[cols_.name];
		//signal_(category);
	}
}

void WindowSubCategory::setData( std::map<Item::Type, std::vector<std::string> >& datas )
{
	lStore_->clear();
	std::map<Item::Type, std::vector<std::string> >::iterator it = datas.begin();

	for(it; it != datas.end(); it++)
	{
		Item::Type itemType = (*it).first;
		std::vector<std::string> categories = (*it).second;

		for(std::vector<std::string>::iterator itCate = categories.begin();
			itCate != categories.end();
			itCate++ )
		{
			Gtk::TreeModel::Row row = *(lStore_->append());
			row[cols_.isSelected] = false;
			row[cols_.icon] = itemType;
			row[cols_.name] = (*itCate);
		}

		//std::for_each(categories.begin(), categories.end(), )
	}
}