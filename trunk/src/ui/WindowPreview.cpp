#include "oot.h"
#include "WindowPreview.h"

#include "Item.h"

#include <glibmm.h>

extern "C" {
#include <gtkhtml/gtkhtml.h>
}

WindowPreview::WindowPreview(void)
{
	html_ = gtk_html_new();
	htmlview_ = Glib::wrap(html_);

	tbnText_.set_label("Text");
	tbnHtml_.set_label("Html");
	tbnSave_.set_label("Save");

	Pango::FontDescription font;

	font.set_family("Mono");

	tview_.modify_font(font);

	scrolled_.add(tview_);

	toolbar_.append(tbnSave_);
	toolbar_.append(tbnText_);
	toolbar_.append(tbnHtml_);

	vbox_.pack_start(toolbar_, Gtk::PACK_SHRINK);
	vbox_.add(scrolled_);

	
	add(vbox_);


	tbnSave_.signal_clicked().connect(
		sigc::mem_fun(*this, &WindowPreview::onSaveClicked)
		);

	tbnText_.signal_clicked().connect(
		sigc::mem_fun(*this, &WindowPreview::onTextClicked)
		);

	tbnHtml_.signal_clicked().connect(
		sigc::mem_fun(*this, &WindowPreview::onHtmlClicked)
		);

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowPreview::~WindowPreview(void)
{
}

void WindowPreview::setViewItem( Item* item )
{
	bool isSet = false;

	if(item->getType() == Item::Text)
	{
		Glib::RefPtr<Gtk::TextBuffer> buffer = tview_.get_buffer();
		buffer->set_text(item->getContents());

		setTextToHtmlView(item->getContents());

		isSet = true;
	}

	if(isSet)
	{
		itemType_ = scast<int>(item->getType());
		itemIdx_ = item->getIdx();
	}
	else
	{
		itemType_ = -1;
		itemIdx_ = 0;
	}
}

void WindowPreview::onSaveClicked()
{
	if(itemType_ < 0) return;

	if(itemIdx_ == scast<int>(Item::Text))
	{
		Glib::RefPtr<Gtk::TextBuffer> buffer = tview_.get_buffer();
		
		signalSave_(itemType_, itemIdx_, buffer->get_text());
	}
}

void WindowPreview::onTextClicked()
{
	scrolled_.remove();
	scrolled_.add(tview_);

	scrolled_.show_all_children();
}


void WindowPreview::onHtmlClicked()
{
	Glib::RefPtr<Gtk::TextBuffer> buffer = tview_.get_buffer();
	setTextToHtmlView(buffer->get_text());

	scrolled_.remove();
	scrolled_.add(*htmlview_);

	scrolled_.show_all_children();
}

ConnectionType WindowPreview::registerHandlerItemSave( SignalItemSaveType::slot_function_type func )
{
	return signalSave_.connect(func);
}

void WindowPreview::setTextToHtmlView( const ustring& text )
{
	GtkHTMLStream* stream = gtk_html_begin(GTK_HTML(html_));
	gtk_html_write(GTK_HTML(html_), stream, text.c_str(), text.size());
	gtk_html_end(GTK_HTML(html_), stream, GTK_HTML_STREAM_OK);
}
