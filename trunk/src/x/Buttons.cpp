#include "oot.h"
#include "Buttons.h"
#include <iostream>

Buttons::Buttons(void)
	:rdGroup(),
	normalBtn("_Normal Button"),
	toggleBtn("_Toggle"),
	spinBtn(),
	chkBtn("_check")
	//rdBtn(rdGroup,"_Rd Btuuon1"),
	//rd2Btn(rdGroup,"_Rd Btuuon2"),
	//rd3Btn(rdGroup,"_Rd Btuuon3")
{
	set_title("Test01 - Buttons");
	set_border_width(10);

	normalBtn.signal_clicked().connect( sigc::mem_fun(this, &Buttons::on_normal_btn_clicked));
	add(normalBtn);
	//this->add(toggleBtn);
	//this->add(spinBtn);
	//this->add(chkBtn);
	//this->add(rdBtn);
	//this->add(rd2Btn);
	//this->add(rd3Btn);

	show_all_children();

}

Buttons::~Buttons(void)
{
}

void Buttons::on_normal_btn_clicked()
{
	Gtk::MessageDialog msgDlg("normal button clicked", false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK_CANCEL, true);
	
	msgDlg.run();
}

