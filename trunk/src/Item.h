#pragma once

#include "oot.h"
#include <vector>

#include "Tags.h"

namespace item {
	enum Type{
		Task,
		Text,
		Photo,
		Picture,
		Document,
		Game,
		Music,
		Binary,
		Event
	};
}

class Item
{
public:
	Item(void);
	~Item(void);

public:
	unsigned id;
	
	std::tstring title;
	std::tstring contents;
	Tags tags;

	Glib::Date getDateForDisplay() { return createdDate_; }

protected:
	void setCreatedDate(Glib::Date& date) { createdDate_ = date; }

private:
	Glib::Date createdDate_;

};
