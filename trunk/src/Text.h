#pragma once

#include "Item.h"

class Text : public Item
{
public:
	Text(void);
	~Text(void);

	virtual Item::Type getType() { return Item::Text; }
	virtual DateTimeType getDateForDisplay() { return createdDate_; }
	virtual std::wstring getTitle() { return title_; }
	virtual std::wstring getContents() { return contents_; }

	std::wstring getMarkdwonContents() { return contents_; }
	void setTitle(const std::wstring& title) { title_ = title; }
	void setContents(const std::wstring& contents) { contents_ = contents; }

private:
	std::wstring title_;
	std::wstring contents_;
	DateTimeType createdDate_;
	bool isCompleted_;
};
