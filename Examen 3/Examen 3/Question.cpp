#include "Question.h"

Question::Question(int id, string question, int parent, bool isLeft)
{
	this->id = id;
	this->question = question;
	this->parent = parent;
	this->isLeft = isLeft;
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

void Question::setParent(int parent)
{
	this->parent = parent;
}

void Question::setIsLeft(bool isLeft)
{
	this->isLeft = isLeft;
}

int Question::getId()
{
	return id;
}

string Question::getQuestion()
{
	return question;
}

int Question::getParent()
{
	return parent;
}

bool Question::getIsLeft()
{
	return isLeft;
}
