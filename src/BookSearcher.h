//BookSearcher.h
//class BookSearcher

#ifndef _BOOKSEARCHER_H_
#define _BOOKSEARCHER_H_

#include "common.h"

//查询结果
//--一共有几种
//--在架的有几种
//--索书号是多少

class BookSearcher
{
public:
  static BookSearcher* Instance();

	void search();
  void searchByTitle(std::string title);
	void searchByAuthor(std::string author);
	void searchByISBN(std::string ISBN);

protected:
	BookSearcher();

private:
  static BookSearcher *instance;

};

#endif
