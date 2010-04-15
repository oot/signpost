#ifndef __TAGS_H__
#define __TAGS_H__

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
	std::string get(int idx);
	bool has(const std::string& tag);
	void add(const std::string& tag);
	void clear();
	void remove(const std::string& tag);
	std::string toString();

private:
	std::vector<std::string> tags_;
	//boost::mutex mutex_;
};


#endif // __TAGS_H__
