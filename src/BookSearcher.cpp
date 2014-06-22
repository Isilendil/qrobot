//BookSearcher.cpp

#include "BookSearcher.h"

using std::string;

BookSearcher *BookSearcher::instance = 0;

BookSearcher::BookSearcher()
{
}

BookSearcher* BookSearcher::Instance()
{
	if (instance == 0)
	{
		instance = new BookSearcher;
	}
	return instance;
}


void BookSearcher::search()
{
	string speechInput;

	while (true)
	{
		SpeechOutput::Instance()->speakUp("请选择查询方式");
		SpeechOutput::Instance()->speakUp("题名责任者还是ISBN号");
		speechInput = SpeechInput::Instance()->waitingForInput();
		if (SemanticAnalysis::Instance()->synonymous(speechInput, "题名"))
		{
			//search
			return;
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "责任者"))
		{
			//search
			return;
		}
		else if (SemanticAnalysis::Instance()->synonymous(speechInput, "ISBN号"))
		{
			//search
			return;
		}
		else
		{
			SpeechOutput::Instance()->speakUp("输入错误");
			SpeechOutput::Instance()->speakUp("是否重新选择");
			speechInput = SpeechInput::Instance()->waitingForInput();
			if (SemanticAnalysis::Instance()->synonymous(speechInput, "是"))
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
}

void BookSearcher::searchByTitle(string title)
{
}

void BookSearcher::searchByAuthor(string author)
{
}

void BookSearcher::searchByISBN(string ISBN)
{
}

