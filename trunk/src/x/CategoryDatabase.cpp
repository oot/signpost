#include "oot.h"
#include "CategoryDatabase.h"

CategoryDatabase::CategoryDatabase( Glib::ustring tableName, sqlite3x::sqlite3_connection* db )
{
	tableName_ = tableName;
	db_ = db;
}
CategoryDatabase::~CategoryDatabase(void)
{
}

void CategoryDatabase::createTable()
{
	Glib::ustring query("CREATE TABLE ");

	query.append(tableName_ + "(" );

	query.append("Idx integer primary key");
	query.append(",");
	query.append("Name varchar(260) not null");
	query.append(",");
	query.append("unique(Name)");

	query.append(");");

	sqlite3x::sqlite3_command cmd(*getDb(), query.c_str());

	cmd.executenonquery();
}