#include "Question.h"

Question::Question(int id, string question, bool isLeft)
{
	this->id = id;
	this->question = question;

	this->isQuestion = isLeft;
}

Question::Question()
{
}

Question::~Question()
{
}

void Question::setId(int id)
{
	this->id = id;
}

void Question::setQuestion(string question)
{
	this->question = question;
}



void Question::setIsQuestion(bool isLeft)
{
	this->isQuestion = isLeft;
}

int Question::getId()
{
	return id;
}

string Question::getQuestion()
{
	return question;
}



bool Question::getIsQuestion()
{
	return isQuestion;
}
