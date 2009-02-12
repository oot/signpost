#pragma once

#include "oot.h"
#include <vector>
#include <boost/thread.hpp>

class Tags
{
public:
	Tags(void);
	~Tags(void);

public:
	int getCount();
	std::tstring get(int idx);
	bool has(const std::tstring& tag);
	void add(const std::tstring& tag);
	void clear();

private:
	std::vector<std::tstring> tags_;
	boost::mutex mutex_;
};
