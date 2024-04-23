#include"std.h"
#include"Question.h"
class ArbolBinario {

private:
    struct Nodo {
        Question question;
        Nodo* left;
        Nodo* right;

        Nodo(Question question) :  question(question), left(nullptr), right(nullptr) {}
    };

    Nodo* raiz;
    void insertarElemento(Nodo*& nodo,Question question);
    Nodo* buscarElemento(Nodo* nodo, Question question);
  
public:
    ArbolBinario();
    ~ArbolBinario();
    void insertarElemento(Question question);
    Nodo* buscarElemento(Question question);
    void hacerPregunta();
    
};



