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
	std::wstring get(int idx);
	bool has(const std::wstring& tag);
	void add(const std::wstring& tag);
	void clear();
	void remove(const std::wstring& tag);
	std::wstring toString();

private:
	std::vector<std::wstring> tags_;
	boost::mutex mutex_;
};
