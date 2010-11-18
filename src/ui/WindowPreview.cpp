#include "oot.h"
#include "WindowPreview.h"

#include "Item.h"

#include <glibmm.h>

WindowPreview::WindowPreview(void)
{
	tbnText_.set_label("Text");
	tbnHtml_.set_label("Html");

	scrolled_.add(tview_);

	toolbar_.append(tbnText_);
	toolbar_.append(tbnHtml_);

	vbox_.pack_start(toolbar_, Gtk::PACK_SHRINK);
	vbox_.add(scrolled_);

	
	add(vbox_);

	show_all_children();

	//////////////////////////////////////////////////////////////////////////

}

WindowPreview::~WindowPreview(void)
{
}

void WindowPreview::setViewItem( Item* item )
{
	item_ = item;

	if(item_->getType() == Item::Todo)
	{
		Glib::RefPtr<Gtk::TextBuffer> buffer;
		buffer->set_text(item_->getContents());

		tview_.set_buffer(buffer);
	}
}
