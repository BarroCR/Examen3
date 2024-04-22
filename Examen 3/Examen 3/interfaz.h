#pragma once
#include"std.h"
#include"ArbolBinario.h"
class interfaz
{

    struct Question {
        string id;
        string question;
        string parent;
        bool value;
    };



public:

	void menu();
};

