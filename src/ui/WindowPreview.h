#pragma once

#include <gtkmm.h>
#include "BoostTypes.h"

class Item;

typedef boost::signal<void(int, unsigned, ustring&)>				SignalItemSaveType;

class WindowPreview : public Gtk::ScrolledWindow
{
public:
	WindowPreview(void);
	~WindowPreview(void);

	void setViewItem(Item* item);

	ConnectionType registerHandlerItemSave(SignalItemSaveType::slot_function_type func);

private:

	void onSaveClicked();
	void onTextClicked();
	void onHtmlClicked();

	void setTextToHtmlView(const ustring& text);

	Gtk::VBox vbox_;
	Gtk::ScrolledWindow scrolled_;
	Gtk::TextView	  tview_;
	Gtk::Toolbar	  toolbar_;

	Gtk::ToolButton tbnText_;
	Gtk::ToolButton tbnHtml_;
	Gtk::ToolButton tbnSave_;

	GtkWidget *html_;
	Gtk::Widget* htmlview_;

	int itemType_;
	unsigned itemIdx_;

	SignalItemSaveType signalSave_;
};
