#pragma once

#include "Item.h"

class TodoItem : public Item
{
public:
	TodoItem(void);
	~TodoItem(void);

	virtual Item::Type getType() { return Item::Todo; }
	virtual DateTimeType getDateForDisplay() { return completedDate_; }
	virtual std::tstring getTitle() { return title_; }
	virtual std::tstring getContents() { return contents_; }

	void setTitle(const std::tstring& title) { title_ = title; }
	void setContents(const std::tstring& contents) { contents_ = contents; }
	void setCompleted(bool isCompleted) { isCompleted_ = isCompleted; }
	bool isCompleted() { return isCompleted_; }

private:
	std::tstring title_;
	std::tstring contents_;
	DateTimeType completedDate_;
	bool isCompleted_;

};
