#include "oot.h"
#include "WindowSubCategory.h"
#include <gdkmm.h>

WindowSubCategory::WindowSubCategory(void)
: lvText_(0)
{
	//add(vbox_);
	pack_start(toolbar_, false, true, 0);
	pack_start(sWindow_);

	toolbar_.set_toolbar_style(Gtk::TOOLBAR_TEXT);
	toolbar_.append(tbuttonNew_, sigc::mem_fun(*this, &WindowSubCategory::onButtonNew));
	toolbar_.append(tbuttonDelete_, sigc::mem_fun(*this, &WindowSubCategory::onButtonDelete));

	tbuttonNew_.set_label("new");
	tbuttonDelete_.set_label("delete");

	sWindow_.add(lvText_);
	sWindow_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);

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
		CategorySelect item;

		item.category = row[cols_.name];
		item.isSelected = row[cols_.isSelected];
		int itemType = row[cols_.type];

		item.type = scast<Item::Type>(itemType);

		vector<CategorySelect>::iterator itSelected = find(selectedItems_.begin(), selectedItems_.end(), item);

		if(itSelected != selectedItems_.end())
		{
			(*itSelected) = item;
		}
		else
		{
			selectedItems_.push_back(item);
		}

		signal_(selectedItems_);
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
			row[cols_.type] = itemType;
			row[cols_.name] = (*itCate);
			row[cols_.icon] = Gtk::Image("./signpost-category-txt.png").get_pixbuf();
		}

		//std::for_each(categories.begin(), categories.end(), )
	}
}

ConnectionType WindowSubCategory::changeHandler( SignalCategoriesSelectType::slot_function_type func )
{
	return signal_.connect(func);
}

void WindowSubCategory::onButtonNew()
{

}

void WindowSubCategory::onButtonDelete()
{
	Gtk::ListViewText::SelectionList slist = lvText_.get_selected();

	if(slist.empty()) return;

	unsigned idx = slist[0];

//	ustring str = lvText_.get_text(idx, 1);
}


