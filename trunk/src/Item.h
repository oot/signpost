#ifndef __ITEM_H__
#define __ITEM_H__

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

	enum Type : int { Todo, Text, Contact, Photo, Picture, Document, Game, Music, Binary, Event, Location, TypeMax };

	enum View : int { 
		ViewDetail,
		ViewList,
		ViewSummary,
	};

public:
	virtual Item::Type getType() const = 0;
	virtual DateTimeType getDisplayDate() const = 0;
	virtual std::string getTitle() const = 0;
	virtual std::string getContents() const = 0;
	virtual std::string getPath() const = 0;
	virtual DateTimeType getDateTime(View view) const = 0;
	
	void getTags(Tags* tags);
	void setIdx(unsigned idx) {idx_ = idx; }
	unsigned getIdx() { return idx_; }
	
private:
	Tags tags_;
	unsigned idx_;

};

#endif // __ITEM_H__
