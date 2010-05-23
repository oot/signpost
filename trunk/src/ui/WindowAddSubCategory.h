/*
 * WindowAddSubCategory.h
 *
 *  Created on: 2010. 5. 21.
 *      Author: oot
 */

#ifndef WINDOWADDSUBCATEGORY_H_
#define WINDOWADDSUBCATEGORY_H_

#include <gtkmm.h>

class TextReader;

class WindowAddSubCategory : public Gtk::Window
{
public:
	WindowAddSubCategory();
	virtual ~WindowAddSubCategory();

public:
	void setTextReader(TextReader* reader);


private:
	void onButtonOk();
	void onButtonCancel();

private:
	Gtk::VBox vbox_;

	Gtk::HBox hboxCategory_;
	Gtk::HBox hboxTitle_;
	Gtk::HBox hboxContent_;
	Gtk::HBox hboxTags_;
	Gtk::HBox hboxButton_;

	Gtk::Label labelCategory_;
	Gtk::Label labelTitle_;
	Gtk::Label labelContent_;
	Gtk::Label labelTags_;

	Gtk::Entry entryCategory_;
	Gtk::Entry entryTitle_;
	Gtk::Entry entryTags_;
	Gtk::Entry entryContent_;
	//Gtk::TextView tviewContent_;

	Gtk::Button buttonOk_;
	Gtk::Button buttonCancel_;

	TextReader* reader_;
};

#endif /* WINDOWADDSUBCATEGORY_H_ */
