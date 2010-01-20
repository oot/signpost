#include "oot.h"
#include "WindowList.h"

WindowList::WindowList(void)
: lvText_(0, true, Gtk::SELECTION_SINGLE)
{
	add(lvText_);

	lstore_ = LstoreItemList::create(cols_);
	lvText_.set_model(lstore_);
	lvText_.append_column("item", cols_.itemType);
	lvText_.append_column("title", cols_.title);

	lstore_->signal_row_changed().connect(
		sigc::mem_fun(*this, &WindowList::onRowChanged)
		);

	//////////////////////////////////////////////////////////////////////////

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowList::~WindowList(void)
{
}

void WindowList::setItemData( std::vector<Text> txts )
{
	lstore_->clear();

	vector<Text>::iterator it = txts.begin();

	for(it; it != txts.end(); it++)
	{
		Text txt = (*it);

		Gtk::TreeModel::Row row = *(lstore_->append());
		row[cols_.itemType] = scast<int>(txt.getType());
		row[cols_.title] = txt.getTitle();
	}
}

void WindowList::onRowChanged( const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& it )
{
	Gtk::TreeRow row = (*it);
	if(row)
	{
		;
	}
}