#pragma once

#include "oot.h"
#include "item.h"

class TaskItem
{
public:
	TaskItem(void);
	~TaskItem(void);

	Glib::ustring getFinishedDate();
	Glib::ustring getPlannedDate();
	Glib::ustring getTitle();
	Glib::ustring getContent();
	bool IsCompleted();

	void getListViewData();
	void getDetailViewData();
	void getCalendarViewData();

	void setIdx(int idx);
	void setTitle(Glib::ustring& title);
	void setContent(Glib::ustring& content);
	void setCompleted(bool isCompleted);


private:
	int idx_;
	Glib::ustring title_;
	Glib::ustring content_;
	bool isCompleted_;
	Glib::ustring completedDate_;
	Glib::ustring plannedDate_;
	
};
