//Database.cpp

Database *Database::instance = 0;

Database::Database()
{
}

Database* Database::Instance()
{
	if (instance == 0)
	{
		instance = new Database;
	}
	return instance;
}

