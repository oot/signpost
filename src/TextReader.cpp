#include "oot.h"
#include "TextReader.h"
#include "oot/Util.h"

TextReader::TextReader(void)
: isOpened_(false)
{
}

TextReader::~TextReader(void)
{
}

bool TextReader::open( const std::string& databasePath )
{
	if(isOpened()) return true;

	std::string dbPath(databasePath);
	dbPath.append(util::getDirDelimeter());
	dbPath.append("Text.db");

	try
	{
		db_.open(dbPath.c_str());
		isOpened_ = true;
	}
	catch (...)
	{
		isOpened_ = false;
	}

	return isOpened_;
}

bool TextReader::verifyTable(const std::string& tableName)
{
	bool ret = true;

	try
	{
		ret = db_.tableExists(tableName.c_str());
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;
}

bool TextReader::createTextTable()
{
	bool ret = true;

	std::string query("CREATE TABLE ");

	query.append("Text (" );

	query.append("idx INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL, ");
	query.append("category VARCHAR NOT NULL, ");
	query.append("title VARCHAR NOT NULL, ");
	query.append("content TEXT, ");
	query.append("path VARCHAR NOT NULL, ");
	query.append("create_date DATETIME NOT NULL  DEFAULT CURRENT_DATE, ");
	query.append("modify_date DATETIME NOT NULL  DEFAULT CURRENT_DATE");
	query.append(");");

	try
	{
		db_.execQuery(query.c_str());
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;
}

bool TextReader::add( Text& text )
{
	string relPath(text.getCategory());
	string absPath(path_);
	absPath.append(util::getDirDelimeter());
	absPath.append(relPath);

	if(util::existDir(absPath) == false)
		util::makeDir(absPath);

	string filename(util::getCurrentDateTime());
	filename.append(" - ");
	filename.append(text.getTitle());
	filename.append(".txt");

	
	relPath.append(util::getDirDelimeter());
	relPath.append(filename);

	absPath.append(util::getDirDelimeter());
	absPath.append(filename);

	text.setPath(relPath);

	std::stringstream query;
	query	<< "INSERT INTO Text "
			<< "(category, title, content, path) VALUES ('"
			<< text.getCategory() << "','"
			<< text.getTitle() << "','"
			<< text.getContents() << "','"
			<< text.getPath() << "');";
	query.flush();

	bool ret = true;

	try
	{
		db_.execQuery(query.str().c_str());
	}
	catch (...)
	{
		ret = false;
	}

	ofstream out(absPath.c_str(), ios::out);

	if(out)
	{
		out << text.getContents();
		out.flush();
		out.close();
		ret = true;
	}
	else
	{
		ret = false;
	}

	if(ret == false) return ret;

	std::string sql("SELECT idx FROM Text ORDER BY idx DESC;");

	try
	{
		text.setIdx(db_.execScalar(sql.c_str()));
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;

}

bool TextReader::update( Text& text )
{
	std::stringstream query;
	query	<< "UPDATE Text "
			<< "SET ("
			<< "category = '"	<< text.getCategory()	<< "',"
			<< "title = '"		<< text.getTitle()		<< "',"
			<< "content = '"	<< text.getContents()		<< "',"
			<< "path = '"		<< text.getPath()	<< "')"
			<< "WHERE (idx = "  << text.getIdx()		<< ");";
	query.flush();

	bool ret = true;

	try
	{
		db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;
}

bool TextReader::del( Text& text )
{
	std::stringstream query;
	query	<< "DELETE FROM Text "
			<< "WHERE (idx = "  << text.getIdx()		<< ");";
	query.flush();

	bool ret = true;

	try
	{
		db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;
}

std::vector<Text> TextReader::getTotal()
{
	std::stringstream query;
	query << "SELECT idx, category, title, content, path, create_date, modify_date FROM Text;";
	query.flush();

	std::vector<Text> txts;
	CppSQLite3Query q;

	try
	{
		q = db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		return txts;
	}

	Text txt;

	for(; !q.eof(); q.nextRow())
	{
		txt.setIdx(q.getIntField("idx"));
		txt.setCategory(q.getStringField("category"));
		txt.setTitle(q.getStringField("title"));
		txt.setContents(q.getStringField("content"));
		// create_date
		// modify_date
		txts.push_back(txt);
	}

	return txts;
}

bool TextReader::createTagsTable()
{
	bool ret = true;

	std::string query("CREATE TABLE ");

	query.append("Tags (" );

	query.append("idx INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL, ");
	query.append("content_idx INTEGER NOT NULL, ");
	query.append("name VARCHAR NOT NULL, ");
	query.append("type INTEGER NOT NULL");
	query.append(");");

	try
	{
		db_.execQuery(query.c_str());
	}
	catch (std::exception ex)
	{
		ret = false;
	}

	return ret;
}

bool TextReader::isOpened()
{
	return isOpened_;
}

bool TextReader::close()
{
	try
	{
		db_.close();
		isOpened_ = false;
	}
	catch (...)
	{
		;
	}

	return !isOpened_;
}

bool TextReader::initialize()
{
	bool result = false;

	if(isOpened() == false) 
		result = open(path_);

	if(!result) return false;

	if(verifyTable("Text") == false) 
		result = createTextTable();

	if(!result) return false;

	if(verifyTable("Tags") == false) 
		result = createTagsTable();

	if(!result) return false;

	return true;
}

void TextReader::setPath( const std::string& path )
{
    if(util::existDir(path) == false) util::makeDir(path);

	path_ = path;
}

std::vector<std::string> TextReader::getCategories()
{
	std::stringstream query;
	query << "SELECT DISTINCT(category) FROM Text;";
	query.flush();

	std::vector<std::string> categories;
	CppSQLite3Query q;

	try
	{
		q = db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		return categories;
	}

	for(; !q.eof(); q.nextRow())
	{
		categories.push_back(q.getStringField("category"));
	}

	return categories;
}

std::vector<Text> TextReader::get( std::vector<std::string> categories )
{
	std::vector<Text> txts;
	CppSQLite3Query q;
	std::stringstream query;

	if(categories.empty()) return txts;

	query << "SELECT idx, category, title, content, path, create_date, modify_date FROM Text ";
	if(categories.empty() == false)
	{
		query << "WHERE ";

		for(unsigned i = 0; i < categories.size(); i++)
		{
			if(i) query << "OR ";
			query << "(category = '" << categories[i] << "') ";
		}
	}
	query.flush();

	
	try
	{
		q = db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		return txts;
	}
	catch(...)
	{
		return txts;
	}

	Text txt;

	for(; !q.eof(); q.nextRow())
	{
		txt.setIdx(q.getIntField("idx"));
		txt.setCategory(q.getStringField("category"));
		txt.setTitle(q.getStringField("title"));
		txt.setContents(q.getStringField("content"));
		// create_date
		// modify_date
		txts.push_back(txt);
	}

	return txts;
}

Text TextReader::get( const unsigned idx )
{
	std::stringstream query;
	query << "SELECT idx, category, title, content, path, create_date, modify_date FROM Text WHERE idx = " << idx << ";";
	query.flush();

	CppSQLite3Query q;
	Text txt;

	try
	{
		q = db_.execQuery(query.str().c_str());
	}
	catch (std::exception ex)
	{
		return txt;
	}

	

	for(; !q.eof(); q.nextRow())
	{
		txt.setIdx(q.getIntField("idx"));
		txt.setCategory(q.getStringField("category"));
		txt.setTitle(q.getStringField("title"));
		txt.setContents(q.getStringField("content"));
		// create_date
		// modify_date
	}

	return txt;
}

bool TextReader::update( const unsigned idx, const ustring& content )
{
	std::stringstream query;
	query	<< "UPDATE Text "
		<< "SET "
		<< "content = '"	<< content		<< "' "
		<< "WHERE idx = "  << idx			<< ";";
	query.flush();

	bool ret = true;

	try
	{
		db_.execQuery(query.str().c_str());
	}
	catch(CppSQLite3Exception& ex)
	{
		clog << ex.errorMessage() << endl;
		ret = false;
	}
	catch (std::exception& ex)
	{
		clog << ex.what() << endl;
		ret = false;
	}

	return ret;
}
