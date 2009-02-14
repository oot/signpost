#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Buttons : public Gtk::Window
{
public:
	Buttons(void);
	~Buttons(void);

	void on_normal_btn_clicked();

private:
	Gtk::ToggleButton toggleBtn;
	Gtk::Button normalBtn;
	Gtk::SpinButton spinBtn;
	Gtk::CheckButton chkBtn;
	Gtk::RadioButton rdBtn;
	Gtk::RadioButton rd2Btn;
	Gtk::RadioButton rd3Btn;
	Gtk::RadioButtonGroup rdGroup;

};
