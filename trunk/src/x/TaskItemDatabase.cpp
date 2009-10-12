#include "oot.h"
#include "TaskItemDatabase.h"
#include <string>
#include <strstream>

/*
TaskItemDatabase::TaskItemDatabase( Glib::ustring& tableName, sqlite3x::sqlite3_connection* db )
{
	tableName_ = tableName;
	db_ = db;

	if (existTable() == false )
		createTable();

}
TaskItemDatabase::~TaskItemDatabase(void)
{
}

bool TaskItemDatabase::createTable()
{
	Glib::ustring query("CREATE TABLE ");

	query.append(tableName_ + "(" );

	query.append("Idx INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL");
	query.append(",");
	query.append("Title VARCHAR NOT NULL");
	query.append(",");
	query.append("Content TEXT");
	query.append(",");
	query.append("Category INTEGER NOT NULL  DEFAULT 0");
	query.append(",");
	query.append("IsComplete INTEGER NOT NULL  DEFAULT 0");
	query.append(",");
	query.append("CompletedDate DATETIME");
	query.append(",");
	query.append("PlannedDate DATETIME NOT NULL  DEFAULT CURRENT_DATE");


	query.append(");");


	sqlite3x::sqlite3_command cmd(*getDb(), query.c_str());

	cmd.executenonquery();

	return true;

}

bool TaskItemDatabase::existTable()
{
	return getDb()->existtable(tableName_.c_str());
}

void TaskItemDatabase::searchAndCallback( ISearchCondition& condition, std::tr1::function<void(TaskItem&)> func)
{
	TaskItem item;
	Glib::ustring sql("SELECT * FROM ");
	sql.append(tableName_ + ";" );

	sqlite3x::sqlite3_command cmd(*getDb(), sql.c_str());

	sqlite3x::sqlite3_reader reader = cmd.executereader();

	while( reader.read() )
	{
		item.setIdx( reader.getint(0) );
		Glib::ustring titleData( reader.gewstring(1).c_str());
		item.setTitle( titleData );
		Glib::ustring contentData( reader.gewstring(2).c_str());
		item.setContent( contentData );
		item.setCompleted( (reader.getint(3) > 0) );

		func(item);
	}
}

int TaskItemDatabase::addItem( TaskItem& item )
{
	std::stringstream sql;
	sql << "INSERT INTO " << tableName_.c_str() 
		<< " (Title, Content, IsComplete, CompletedDate, PlannedDate) VALUES ('"
		<< item.getTitle() << "','"
		<< item.getContent() << "','"
		<< item.IsCompleted() << "','"
		<< item.getFinishedDate() << "','"
		<< item.getPlannedDate() << "');";

	sqlite3x::sqlite3_command cmd(*getDb(), sql.str().c_str());

	cmd.executenonquery();

	return 0;


}


*/