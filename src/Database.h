//Database.h
//class Database

#ifndef _DATABASE_H_
#define _DATABASE_H_

class Database
{
public:
  static Database* Instance();
	
protected:
  Database();

private:
  static Database *instance;

};

#endif
