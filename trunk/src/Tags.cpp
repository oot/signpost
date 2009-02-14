#include "oot.h"
#include "Tags.h"
#include "oot/Util.h"

Tags::Tags(void)
{
}

Tags::~Tags(void)
{
}


int Tags::getCount()
{
	boost::mutex::scoped_lock lock(mutex_);
	return tags_.size();
}

bool Tags::has(const std::tstring& tag)
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::tstring>::iterator iter = tags_.begin();

	while(iter != tags_.end())
	{
		if( tag.compare( (*iter) ) == 0)
			return true;

		iter++;
	}

	return false;
}

std::tstring Tags::get(int idx)
{
	boost::mutex::scoped_lock lock(mutex_);

	if( (tags_.size() + 1) > (unsigned)idx)
		return _T("");
	
	return tags_[idx];
}

void Tags::add(const std::tstring& tag)
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::tstring>::iterator iter = tags_.begin();

	while(iter != tags_.end())
	{
		if( tag.compare( (*iter) ) == 0)
		{
			return;
		}
		iter++;
	}

	tags_.push_back(tag);
}

void Tags::clear()
{
	boost::mutex::scoped_lock lock(mutex_);
	tags_.clear();
}

std::tstring Tags::toString()
{
	boost::mutex::scoped_lock lock(mutex_);
	return oot::util::combine(tags_, _T(","));
}

void Tags::remove( const std::tstring& tag )
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::tstring>::iterator iter = tags_.begin();

	while(iter != tags_.end())
	{
		if( tag.compare( (*iter) ) == 0)
		{
			tags_.erase(iter);
			return;
		}
		iter++;
	}

	return;
}