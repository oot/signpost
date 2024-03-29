#ifndef __TEXT_READER_H__
#define __TEXT_READER_H__

#include "Text.h"
#include "ISearchFilter.h"
#include "cppsqlite3/CppSQLite3.h"

class TextReader
{
public:
	TextReader(void);
	~TextReader(void);

	std::vector<Text*> get(ISearchFilter& filter);

	bool open(const std::string& databasePath);
	bool close();
	bool isOpened();

	bool initialize();
	void setPath(const std::string& path);

	bool add(Text& text);
	bool update(Text& text);
	bool update(const unsigned idx, const ustring& content);
	bool del(Text& text);
	Text get(const unsigned idx);
	std::vector<Text> get(std::vector<std::string> categories);

	std::vector<Text> getTotal();
	std::vector<std::string> getCategories();

	void getTags(Tags* tags, const int idx);

private:
	bool verifyTable(const std::string& tableName);
	bool createTextTable();
	bool createTagsTable();

private:
	bool isOpened_;
	CppSQLite3DB db_;

	std::string path_;
};

#endif // __TEXT_READER_H__
