#include "ArbolBinario.h"

ArbolBinario::ArbolBinario() : raiz(nullptr) {

}

ArbolBinario::~ArbolBinario() {

}



void ArbolBinario::insertarElemento(Nodo*& nodo, Question question)
{
    if (nodo == nullptr) {
        nodo = new Nodo(question); // Si el nodo es nulo, crea un nuevo nodo con el dato proporcionado.
    }
    else if (question.getIsLeft()==true) {
        insertarElemento(nodo->right, question);// Si el dato es menor que el dato del nodo actual, recursivamente inserta en el subárbol izquierdo.
    }
    else if (question.getIsLeft() == false) {
        insertarElemento(nodo->left, question); // Si el dato es mayor que el dato del nodo actual, recursivamente inserta en el subárbol derecho.
    }
}

void ArbolBinario::insertarElemento(Question question)
{
    Nodo* parentNode = buscarElemento(raiz, question);
    if (parentNode != nullptr) {
        cout<<parentNode->question.getId()<<endl;
        insertarElemento(parentNode, question);
    }
    
    else {
        cout << "Nodo padre no encontrado. Insertando como nodo raíz." << endl;
        insertarElemento(raiz, question);
    }
}

ArbolBinario::Nodo* ArbolBinario::buscarElemento(Nodo* nodo, Question question) {

    if (nodo == nullptr || nodo->question.getId() == question.getParent()) {
        return nodo;
    }

    if (question.getIsLeft()==true) {
        cout << question.getParent() << " " << nodo->question.getId() << endl;
        return buscarElemento(nodo->right, question);
    }
    else {
        cout << question.getParent() << " " << nodo->question.getId() << endl;
        return buscarElemento(nodo->left, question);
    }
}

ArbolBinario::Nodo* ArbolBinario::buscarElemento(Question question) {
    Nodo* resultado = buscarElemento(raiz, question);
    
    if (resultado != nullptr) {
        return raiz;
    }
    else {
        return nullptr;
    }
}

//ArbolBinario::Nodo* ArbolBinario::buscarElemento(Nodo* nodo, Question question) {
//    
//    if (nodo == nullptr || nodo->question.getId() == question.getParent()) {
//        return nodo;
//    }
//
//    if (question.getParent() < nodo->question.getId()) {
//        cout << question.getParent() << " " << nodo->question.getId() << endl;
//        return buscarElemento(nodo->right, question);
//        
//    }
//    else {
//        cout << question.getParent() << " " << nodo->question.getId() << endl;
//        return buscarElemento(nodo->left, question);
//    }
//}





