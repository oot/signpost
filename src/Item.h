#pragma once

#include "oot.h"
#include <vector>

#include "Tags.h"
#include <boost/date_time.hpp>

typedef boost::posix_time::ptime DateTimeType;

class Item
{
public:
	Item(void);
	~Item(void);

	enum Type { Todo, Text, Contact, Photo, Picture, Document, Game, Music, Binary, Event };

public:
	virtual Item::Type getType() = 0;
	virtual DateTimeType getDateForDisplay() = 0;
	virtual std::tstring getTitle() = 0;
	virtual std::tstring getContents() = 0;
	
	Tags& getTags() { return tags_; }
	void setIdx(unsigned idx) {idx_ = idx; }
	unsigned getIdx() { return idx_; }
	
private:
	Tags tags_;
	unsigned idx_;

};
