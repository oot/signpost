#pragma once

#include "Item.h"

class Text : public Item
{
public:
	Text(void);
	~Text(void);

	virtual Item::Type getType() const { return Item::Text; }
	virtual DateTimeType getDisplayDate() const { return createdDate_; }
	virtual std::string getTitle() const { return title_; }
	virtual std::string getContents() const { return contents_; }
	virtual DateTimeType getDateTime(View view) const;
	virtual std::string getPath() const {return path_; }

	void setPath(const string& path) {path_ = path; }

	void setCategory(const std::string& category) {category_ = category; }
	std::string getCategory() const {return category_; }

	std::string getMarkdwonContents() { return contents_; }
	void setTitle(const std::string& title) { title_ = title; }
	void setContents(const std::string& contents) { contents_ = contents; }

private:
	std::string title_;
	std::string contents_;
	DateTimeType createdDate_;
	DateTimeType modifiedDate_;
	bool isCompleted_;
	std::string category_;
	std::string path_;
};
