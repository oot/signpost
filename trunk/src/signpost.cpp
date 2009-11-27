#include "oot.h"

#include "ui/WindowSignpost.h"
#include <fstream>

int main(int argc, char** argv)
{
	std::fstream out;
	out.open("signpost.log", std::ios::app);
	std::clog.rdbuf(out.rdbuf());

	Gtk::Main kit(argc, argv);
	WindowSignpost win;
	Gtk::Main::run(win);

	out.close();

	return 0;
}
