#include "oot.h"
#include "WindowSignpost.h"

WindowSignpost::WindowSignpost(void)
:lviewTextItem(5),
tbuttonNew_(Gtk::Stock::NEW),
mitemOpen_("Open"),
mitemClose_("Close"),
mitemQuit_("Quit"),
mitemAbout_("About"),
mitemFile_("File"),
mitemView_("View"),
mitemHelp_("Help")
{

	Gtk::AttachOptions options = Gtk::AttachOptions(0);
	options = (options | Gtk::EXPAND);

	vbox_.pack_start(menubar_, Gtk::PACK_SHRINK);
	vbox_.pack_start(toolbar_, Gtk::PACK_SHRINK);
	vbox_.add(hpaned_);
	vbox_.pack_start(statusbar_, Gtk::PACK_SHRINK);

	hpaned_.pack1(vpanedCategory_, options);
	hpaned_.pack2(hpanedItem_);
	vpanedCategory_.pack1(swinCategory_, options);
	vpanedCategory_.pack2(swinSubCategory_);
	hpanedItem_.pack1(swinItemList_, options);
	hpanedItem_.pack2(swinItemView_);

	swinCategory_.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	swinCategory_.set_size_request(150, 150);
	swinItemList_.add(lviewTextItem);
	swinItemList_.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	swinItemList_.set_size_request(300);
	swinItemView_.add(tviewItem);

	menubar_.add(mitemFile_);
	menubar_.add(mitemView_);
	menubar_.add(mitemHelp_);


	toolbar_.append(tbuttonNew_);

	menuFile_.append(mitemOpen_);
	menuFile_.append(mitemClose_);
	menuFile_.append(mitemQuit_);
	menuHelp_.append(mitemAbout_);

	mitemFile_.set_submenu(menuFile_);
	mitemHelp_.set_submenu(menuHelp_);


	add(vbox_);

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowSignpost::~WindowSignpost(void)
{
}
