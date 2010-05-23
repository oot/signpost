#pragma once

#include <gtkmm.h>

#include "WindowCategory.h"
#include "WindowSubCategory.h"
#include "WindowList.h"
#include "WindowPreview.h"

#include "TextReader.h"

#include "WindowAddText.h"
#include "WindowAddSubCategory.h"

class WindowSignpost : public Gtk::Window
{
public:
	WindowSignpost(void);
	~WindowSignpost(void);



private:
	void initializeItem();
	void onCategoryChange(int itemType);
	void onSubCategoryChange(vector<CategorySelect>& select);
	void changeSubCategory();
	void changeItemList();

	//////////////////////////////////////////////////////////////////////////
	void onButtonAddText();

private:
	Gtk::VBox vbox_;

	Gtk::MenuBar menubar_;
	Gtk::Toolbar toolbar_;
	Gtk::Statusbar statusbar_;

	Gtk::HPaned hpaned_;
	Gtk::HPaned hpanedItem_;

	Gtk::VPaned vpanedCategory_;

	WindowCategory		swinCategory_;
	WindowSubCategory	swinSubCategory_;
	WindowList			swinItemList_;
	WindowPreview		swinItemView_;

	TextReader			textReader_;

	Gtk::Menu menuFile_;
	Gtk::Menu menuView_;
	Gtk::Menu menuHelp_;

	Gtk::MenuItem mitemFile_;
	Gtk::MenuItem mitemView_;
	Gtk::MenuItem mitemHelp_;

	Gtk::MenuItem mitemOpen_;
	Gtk::MenuItem mitemClose_;
	Gtk::MenuItem mitemQuit_;
	Gtk::MenuItem mitemAbout_;
	Gtk::MenuItem mitemTest_;

	Gtk::ToolItem titemNew_;
	Gtk::ToolButton tbuttonNew_;

	//////////////////////////////////////////////////////////////////////////
	// For Test
	//////////////////////////////////////////////////////////////////////////
	Gtk::ToolButton tbuttonAddText_;
	WindowAddSubCategory winAddText;
	//////////////////////////////////////////////////////////////////////////

	Gtk::Menu_Helpers::MenuList mlist_;


	//////////////////////////////////////////////////////////////////////////

	std::vector<bool> selectedCategory_;

};
