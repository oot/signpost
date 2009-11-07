#pragma once

#include <gtkmm.h>

#include "WindowCategory.h"
#include "WindowSubCategory.h"

class WindowSignpost : public Gtk::Window
{
public:
	WindowSignpost(void);
	~WindowSignpost(void);


private:
	Gtk::VBox vbox_;

	Gtk::MenuBar menubar_;
	Gtk::Toolbar toolbar_;
	Gtk::Statusbar statusbar_;

	Gtk::HPaned hpaned_;
	Gtk::HPaned hpanedItem_;

	Gtk::VPaned vpanedCategory_;

	WindowCategory swinCategory_;
	WindowSubCategory swinSubCategory_;
	Gtk::ScrolledWindow swinItemList_;
	Gtk::ScrolledWindow swinItemView_;

	Gtk::ListViewText lviewTextItem;
	Gtk::TextView	  tviewItem;

	Gtk::Menu menuFile_;
	Gtk::Menu menuView_;
	Gtk::Menu menuHelp_;

	Gtk::MenuItem mitemFile_;
	Gtk::MenuItem mitemView_;
	Gtk::MenuItem mitemHelp_;

	Gtk::MenuItem mitemOpen_;
	Gtk::MenuItem mitemClose_;
	Gtk::MenuItem mitemQuit_;
	Gtk::MenuItem mitemAbout_;
	Gtk::MenuItem mitemTest_;

	Gtk::ToolItem titemNew_;
	Gtk::ToolButton tbuttonNew_;

	Gtk::Menu_Helpers::MenuList mlist_;


	//////////////////////////////////////////////////////////////////////////
	//BasicInfo basic;

};
