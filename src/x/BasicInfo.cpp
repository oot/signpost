#include "oot.h"
#include "BasicInfo.h"

/*
BasicInfo::BasicInfo(void)
:isOpened_(false)
{
}

BasicInfo::~BasicInfo(void)
{
}

void BasicInfo::open()
{

	dbconn_.open("paperbox.sqlite3");
	isOpened_ = true;

}

void BasicInfo::initialize()
{
	if( isOpend() == false)
		return;

	Glib::ustring table("category");
	bool isExist = dbconn_.existtable(table.c_str());

	if( isExist == false)
		createTable(table);

}

bool BasicInfo::isOpend()
{
	return isOpened_;
}

void BasicInfo::createTable(Glib::ustring& table)
{
	Glib::ustring query("CREATE TABLE ");

	query.append(table + "(" );

	query.append("Idx integer primary key");
	query.append(",");
	query.append("Name varchar(260) not null");
	query.append(",");
	query.append("unique(Name)");

	query.append(");");

	sqlite3x::sqlite3_command cmd(dbconn_, query.c_str());

	cmd.executenonquery();
}

void BasicInfo::addCategory( int idx, Glib::ustring& name )
{
	categoryList[idx] = name;
}

void BasicInfo::removeCategory( int idx )
{
	if( categoryList.empty() )
		return;

	std::map<int, Glib::ustring>::iterator iter = categoryList.find(idx);

	categoryList.erase(iter);
}

void BasicInfo::addCategoryToDb( Glib::ustring& name )
{
	sqlite3x::sqlite3_command cmd(dbconn_, "INSERT INTO Category (Name) VALUES (?);");
	cmd.bind(1, name.c_str());
	cmd.executenonquery();

	int idx = getCategoryIdFromDb(name);

	if( idx < 0)
		return;

	addCategory(idx, name);

}

int BasicInfo::getCategoryIdFromDb( Glib::ustring& name )
{
	int result = -1;
	Glib::ustring sql("SELECT * FROM Category Where Name = '");
	sql.append(name);
	sql.append("'");

	sqlite3x::sqlite3_command cmd(dbconn_, sql.c_str());
	sqlite3x::sqlite3_reader reader = cmd.executereader();

	while(reader.read()) {
		result = reader.getint(0);
		break;
	}

	return result;

}

std::vector<Glib::ustring> BasicInfo::getCategoryNames()
{
	std::map<int,Glib::ustring>::iterator iter = categoryList.begin();

	std::vector<Glib::ustring> names;
	Glib::ustring name("");

	while( iter != categoryList.end() )
	{
		name = iter->second;
		names.push_back(name);
		iter++;
	}

	return names;
}

void BasicInfo::updateCategoryFromDb()
{
	int idx = -1;
	Glib::ustring name;
	Glib::ustring sql("SELECT * FROM Category");

	sqlite3x::sqlite3_command cmd(dbconn_, sql.c_str());
	sqlite3x::sqlite3_reader reader = cmd.executereader();

	categoryList.clear();

	while(reader.read()) {
		idx = reader.getint(0);
		name = reader.getstring(1).c_str();
		categoryList[idx] = name;
	}
}

int BasicInfo::getCategoryId( Glib::ustring name )
{
	std::map<int,Glib::ustring>::iterator iter = categoryList.begin();

	Glib::ustring categoryName("");

	while( iter != categoryList.end() )
	{
		categoryName = iter->second;
		
		if( categoryName.compare(name) == 0)
			break;

		iter++;
	}
	int idx = iter->first;

	return idx;
}

*/