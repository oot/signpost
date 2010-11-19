#include "oot.h"
#include "WindowSignpost.h"

#include "oot/Util.h"
#include "BoostTypes.h"

WindowSignpost::WindowSignpost(void)
: tbuttonNew_(Gtk::Stock::NEW)
, tbuttonAddText_(Gtk::Stock::ADD)
, mitemOpen_("Open")
, mitemClose_("Close")
, mitemQuit_("Quit")
, mitemAbout_("About")
, mitemFile_("File")
, mitemView_("View")
, mitemHelp_("Help")
{
	set_title("signpost");

	Gtk::AttachOptions options = Gtk::AttachOptions(0);
	options = (options | Gtk::EXPAND);

	vbox_.pack_start(menubar_, Gtk::PACK_SHRINK);
	vbox_.pack_start(toolbar_, Gtk::PACK_SHRINK);
	vbox_.add(hpaned_);
	vbox_.pack_start(statusbar_, Gtk::PACK_SHRINK);
	vbox_.set_size_request(-1, 500);

	hpaned_.pack1(vpanedCategory_, options);
	hpaned_.pack2(hpanedItem_);
	vpanedCategory_.pack1(swinCategory_, options);
	vpanedCategory_.pack2(swinSubCategory_);
	hpanedItem_.pack1(swinItemList_, options);
	hpanedItem_.pack2(swinItemView_);

	swinCategory_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	swinCategory_.set_size_request(150, 150);
	//swinSubCategory_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	swinItemList_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	swinItemList_.set_size_request(300);
	swinItemView_.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	swinItemView_.set_size_request(500);

	menubar_.add(mitemFile_);
	menubar_.add(mitemView_);
	menubar_.add(mitemHelp_);

	toolbar_.append(tbuttonNew_);
	toolbar_.append(tbuttonAddText_);

	menuFile_.append(mitemOpen_);
	menuFile_.append(mitemClose_);
	menuFile_.append(mitemQuit_);
	menuHelp_.append(mitemAbout_);

	mitemFile_.set_submenu(menuFile_);
	mitemHelp_.set_submenu(menuHelp_);

	add(vbox_);

	//////////////////////////////////////////////////////////////////////////
	// Item
	initializeItem();

	swinCategory_.changeHandler(boost::bind(&WindowSignpost::onCategoryChange, this, _1));
	swinSubCategory_.changeHandler(boost::bind(&WindowSignpost::onSubCategoryChange, this, _1));
	swinItemList_.registerHander(boost::bind(&WindowSignpost::onListActivated, this, _1));
	swinItemView_.registerHandlerItemSave(boost::bind(&WindowSignpost::onViewSave, this, _1, _2, _3));

	tbuttonAddText_.signal_clicked().connect(sigc::mem_fun(*this, &WindowSignpost::onButtonAddText));

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowSignpost::~WindowSignpost(void)
{
}

void WindowSignpost::initializeItem()
{
	selectedCategory_.resize((unsigned)Item::TypeMax, false);
	using namespace oot::util;

	std::string path;
	getProgramPath(path);
	path.append(getDirDelimeter());
	path.append("Text");

	util::makeDir(path);

	textReader_.setPath(path);
	textReader_.initialize();
}

void WindowSignpost::onCategoryChange( int itemType )
{
	clog << util::getCurrentDateTime() << " ItemType:" << itemType << endl;

	selectedCategory_[itemType] = !selectedCategory_[itemType];
	changeSubCategory();
}

void WindowSignpost::changeSubCategory()
{
	std::map<Item::Type, std::vector<std::string> > subCategories;
	std::vector<std::string> categories;

	for(unsigned i = 0; i < selectedCategory_.size(); i++)
	{
		if(selectedCategory_[i])
		{
			subCategories[(Item::Type)i] = textReader_.getCategories();
		}
	}

	swinSubCategory_.setData(subCategories);
}

void WindowSignpost::onSubCategoryChange( vector<CategorySelect>& select )
{
	vector<string> categories;

	for(unsigned i = 0; i < select.size(); i++)
	{
		if(select[i].isSelected)
		{
			categories.push_back(select[i].category);
		}
	}

	vector<Text> txts = textReader_.get(categories);
	swinItemList_.setItemData(txts);
}

void WindowSignpost::onButtonAddText()
{
	winAddText.setTextReader(&textReader_);
	winAddText.show_all();
}

void WindowSignpost::onListActivated( unsigned id )
{
	Text text = textReader_.get(id);

	swinItemView_.setViewItem(&text);
}

void WindowSignpost::onViewSave( int type, unsigned idx, ustring& contents )
{
	if(type == Item::Text)
	{
		textReader_.update(idx, contents);
	}
	
}
