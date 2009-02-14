#pragma once

#include "Item.h"

class TextItem : public Item
{
public:
	TextItem(void);
	~TextItem(void);

	virtual Item::Type getType() { return Item::Text; }
	virtual DateTimeType getDateForDisplay() { return createdDate_; }
	virtual std::tstring getTitle() { return title_; }
	virtual std::tstring getContents() { return contents_; }

	std::tstring getMarkdwonContents() { return contents_; }
	void setTitle(const std::tstring& title) { title_ = title; }
	void setContents(const std::tstring& contents) { contents_ = contents; }

private:
	std::tstring title_;
	std::tstring contents_;
	DateTimeType createdDate_;
	bool isCompleted_;
};
