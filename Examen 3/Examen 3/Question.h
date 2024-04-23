#pragma once
#include"std.h"

class Question
{
private:
	int id;
	string question;
	bool isQuestion;
public:
	Question(int id,string question,bool isQuestion);
	Question();
	~Question();

	void setId(int id);
	void setQuestion(string question);
	void setIsQuestion(bool isLeft);

	int getId();
	
	string getQuestion();
	bool getIsQuestion();


















};

