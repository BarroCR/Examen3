#pragma once
#include"std.h"

class Question
{
private:
	int id;
	string question;
	int parent;
	bool isLeft;
public:
	Question(int id,string question,int parent,bool isLeft);
	Question();
	~Question();

	void setId(int id);
	void setQuestion(string question);
	void setParent(int parent);
	void setIsLeft(bool isLeft);

	int getId();
	string getQuestion();
	int getParent();
	bool getIsLeft();


















};

