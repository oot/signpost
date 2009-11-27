#pragma once

#include <gtkmm.h>

#include "TextReader.h"

class WindowPreference : public Gtk::Window
{
public:
	WindowPreference(void);
	~WindowPreference(void);

private:
	Gtk::VBox vbox_;

	Gtk::MenuBar menubar_;
	Gtk::Toolbar toolbar_;
	Gtk::Statusbar statusbar_;

	Gtk::HPaned hpaned_;
	Gtk::HPaned hpanedItem_;

	Gtk::VPaned vpanedCategory_;

	Gtk::Window		winCategory_;
	Gtk::Window		winSubCategory_;
	Gtk::Window		winItemList_;
	Gtk::Window		winContents_;
	Gtk::ListViewText lvTextItem_;

	TextReader			textReader_;

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

	std::vector<bool> selectedCategory_;

};
