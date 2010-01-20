#pragma once

#include <gtkmm.h>

class TextReader;

class WindowAddText : public Gtk::Window
{
public:
	WindowAddText(void);
	~WindowAddText(void);

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
