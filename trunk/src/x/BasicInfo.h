#pragma once

#include "sqlite3x/sqlite3x.h"
#include <vector>
#include <map>

class BasicInfo
{
public:
	BasicInfo(void);
	~BasicInfo(void);

public:
	void open();
	void initialize();

	bool isOpend();


	std::vector<Glib::ustring> getCategoryNames();
	void updateCategoryFromDb();
	int getCategoryId(Glib::ustring name);

	void addCategory(int idx, Glib::ustring& name);
	void removeCategory(int idx);

	void addCategoryToDb(Glib::ustring& name);
	void removeCategoryFromDb(int idx);
	int getCategoryIdFromDb(Glib::ustring& name);

private:
	sqlite3x::sqlite3_connection dbconn_;
	bool isOpened_;

	void createTable(Glib::ustring& table);

	std::map<int, Glib::ustring> categoryList;
};
