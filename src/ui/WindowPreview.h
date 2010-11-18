#pragma once

#include <gtkmm.h>

class Item;

class WindowPreview : public Gtk::ScrolledWindow
{
public:
	WindowPreview(void);
	~WindowPreview(void);

	void setViewItem(Item* item);

private:
	Gtk::VBox vbox_;
	Gtk::ScrolledWindow scrolled_;
	Gtk::TextView	  tview_;
	Gtk::Toolbar	  toolbar_;

	Gtk::ToolButton tbnText_;
	Gtk::ToolButton tbnHtml_;

	Item* item_;
};
