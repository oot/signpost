/*
 * WindowAddSubCategory.cpp
 *
 *  Created on: 2010. 5. 21.
 *      Author: oot
 */
#include "oot.h"
#include "oot.h"

#include "WindowAddSubCategory.h"

#include "TextReader.h"

WindowAddSubCategory::WindowAddSubCategory()
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

	buttonOk_.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddSubCategory::onButtonOk));
	buttonCancel_.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddSubCategory::onButtonCancel));

	show_all_children();
}

WindowAddSubCategory::~WindowAddSubCategory()
{
	// TODO Auto-generated destructor stub
}

void WindowAddSubCategory::setTextReader( TextReader* reader )
{
	g_assert(reader);

	reader_ = reader;
}

void WindowAddSubCategory::onButtonOk()
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

void WindowAddSubCategory::onButtonCancel()
{
	hide_all();
}
