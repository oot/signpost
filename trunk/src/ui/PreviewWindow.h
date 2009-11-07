#pragma once

#include <gtkmm.h>
#include "CategoryListView.h"
#include "CategoryListStore.h"

#include "BasicInfo.h"

class SignpostWindow : public Gtk::Window
{
public:
	SignpostWindow(void);
	~SignpostWindow(void);


private:
	Gtk::VBox vbox_;

	Gtk::MenuBar menubar_;
	Gtk::Toolbar toolbar_;
	Gtk::Statusbar statusbar_;

	Gtk::HPaned hpaned_;
	Gtk::HPaned itemHpaned_;

	Gtk::ScrolledWindow categoryScrolledWindow_;
	Gtk::ScrolledWindow itemScrolledWindows_;

	CategoryColumns categoryListColumns_;
	CategoryListView categoryListView_;
	Glib::RefPtr<Gtk::ListStore> categoryListStoreRef_;
	Gtk::ListViewText itemList_;
	Gtk::TextView detailedItemTextView_;

	Gtk::Menu fileMenu_;
	Gtk::Menu viewMenu_;
	Gtk::Menu helpMenu_;

	Gtk::MenuItem fileMenuItem_;
	Gtk::MenuItem viewMenuItem_;
	Gtk::MenuItem helpMenuItem_;

	Gtk::MenuItem openMenuItem_;
	Gtk::MenuItem closeMenuItem_;
	Gtk::MenuItem quitMenuItem_;
	Gtk::MenuItem aboutMenuItem_;
	Gtk::MenuItem testMenuItem_;

	Gtk::ToolItem newToolItem_;
	Gtk::ToolButton newToolButton_;

	Gtk::Menu_Helpers::MenuList menuList_;


	//////////////////////////////////////////////////////////////////////////
	//BasicInfo basic;

};
