#pragma once

#include "sqlite3x/sqlite3x.h"
#include "ISearchFilter.h"
#include <boost/signals.hpp>

class TaskItemDatabase
{
public:
	TaskItemDatabase(Glib::ustring& tableName, sqlite3x::sqlite3_connection* db);
	~TaskItemDatabase(void);

	//void searchAndCallback(ISearchFilter& condition, std::tr1::function<void(TaskItem&)> );

	//int addItem(TaskItem& item);

	bool existTable();
	bool createTable();


private:
	sqlite3x::sqlite3_connection* getDb() { return db_; }
	sqlite3x::sqlite3_connection* db_;
	Glib::ustring tableName_;

	//boost::signal<void (TaskItem&) > onRead_;

};
