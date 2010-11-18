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
	lvText_.append_column("id", cols_.id);

	lstore_->signal_row_changed().connect(
		sigc::mem_fun(*this, &WindowList::onRowChanged)
		);

	lvText_.signal_row_activated().connect(
		sigc::mem_fun(*this, &WindowList::onRowActivated)
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
		row[cols_.id] = txt.getIdx();
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

void WindowList::onRowActivated( const Gtk::TreeModel::Path& path, const Gtk::TreeViewColumn* column )
{
	ustring pathText = path.to_string();
	Gtk::TreeModel::iterator it = lstore_->get_iter(path);

	Gtk::TreeModel::Row row = (*it);

	unsigned id = row[cols_.id];

	sinalRowActivated_(id);
	
}

ConnectionType WindowList::registerHander( SignalUIntType::slot_function_type func )
{
	return sinalRowActivated_.connect(func);
}
