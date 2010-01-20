#include "oot.h"
#include "WindowAddText.h"
#include "TextReader.h"

WindowAddText::WindowAddText(void)
: reader_(0)
{
	labelCategory_.set_text("category");
	labelTitle_.set_text("title");
	labelContent_.set_text("content");
	labelTags_.set_text("tags");

	buttonCancel_.set_label("cancel");
	buttonOk_.set_label("ok");

	hboxCategory_.pack_start(labelCategory_);
	hboxCategory_.pack_start(entryCategory_);

	hboxTitle_.pack_start(labelTitle_);
	hboxTitle_.pack_start(entryTitle_);

	hboxTags_.pack_start(labelTags_);
	hboxTags_.pack_start(entryTags_);

	hboxContent_.pack_start(labelContent_);
	hboxContent_.pack_start(entryContent_);

	hboxButton_.pack_start(buttonCancel_);
	hboxButton_.pack_start(buttonOk_);

	vbox_.pack_start(hboxCategory_);
	vbox_.pack_start(hboxTitle_);
	vbox_.pack_start(hboxContent_);
	vbox_.pack_start(hboxTags_);
	vbox_.pack_start(hboxButton_);

	add(vbox_);

	buttonOk_.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddText::onButtonOk));
	buttonCancel_.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddText::onButtonCancel));

	show_all_children();
}

WindowAddText::~WindowAddText(void)
{
}

void WindowAddText::setTextReader( TextReader* reader )
{
	g_assert(reader);

	reader_ = reader;
}

void WindowAddText::onButtonOk()
{

	string category = entryCategory_.get_text();
	string title = entryTitle_.get_text();
	string content = entryContent_.get_text();
	string tags = entryTags_.get_text();

	Text text;

	text.setCategory(category);
	text.setContents(content);
	text.setTitle(title);
	
	bool isAddOk = reader_->add(text);

	string msg;
	isAddOk? msg = "ok" : msg = "fail";

	Gtk::MessageDialog dlg(msg.c_str());

	dlg.set_modal(true);
	dlg.run();

	hide_all();
}

void WindowAddText::onButtonCancel()
{
	hide_all();
}