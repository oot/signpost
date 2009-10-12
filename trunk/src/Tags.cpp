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

bool Tags::has(const std::wstring& tag)
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::wstring>::iterator iter = std::find(tags_.begin(), tags_.end(), tag);

	if(iter != tags_.end()) return true;
	else return false;
}

std::wstring Tags::get(int idx)
{
	boost::mutex::scoped_lock lock(mutex_);

	if( (tags_.size() + 1) > (unsigned)idx)
		return L"";

	return tags_[idx];
}

void Tags::add(const std::wstring& tag)
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::wstring>::iterator iter = std::find(tags_.begin(), tags_.end(), tag);

	if(iter == tags_.end()) tags_.push_back(tag);
}

void Tags::clear()
{
	boost::mutex::scoped_lock lock(mutex_);
	tags_.clear();
}

std::wstring Tags::toString()
{
	boost::mutex::scoped_lock lock(mutex_);
	return oot::util::combine(tags_, L",");
}

void Tags::remove( const std::wstring& tag )
{
	boost::mutex::scoped_lock lock(mutex_);

	std::vector<std::wstring>::iterator iter = std::find(tags_.begin(), tags_.end(), tag);

	if(iter != tags_.end()) tags_.erase(iter);

	return;
}
