#pragma once

#include "sqlite3x.h"

class CategoryDatabase
{
public:
	CategoryDatabase(Glib::ustring tableName, sqlite3x::sqlite3_connection* db);

	~CategoryDatabase(void);

	void createTable();
	bool existTable();
	void removeCategory(Glib::ustring& category);
	void addCategory(Glib::ustring& category);
	int getCategoryId(Glib::ustring& category);
	Glib::ustring getCategoryName(int categoryId);
	bool hasCategory(Glib::ustring& category);

private:
	sqlite3x::sqlite3_connection* getDb() {return db_; }
	sqlite3x::sqlite3_connection* db_;
	Glib::ustring tableName_;

};
