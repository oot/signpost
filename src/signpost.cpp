#include "oot.h"

#include "ui/WindowSignpost.h"

int main(int argc, char** argv)
{
	Gtk::Main kit(argc, argv);
	WindowSignpost win;
	Gtk::Main::run(win);

	return 0;
}
