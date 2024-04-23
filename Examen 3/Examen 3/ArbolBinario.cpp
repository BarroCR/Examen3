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
    else if (question.getId()<nodo->question.getId()) {
        insertarElemento(nodo->left, question);// Si el dato es menor que el dato del nodo actual, recursivamente inserta en el subárbol izquierdo.
    }
    else  {
        insertarElemento(nodo->right, question); // Si el dato es mayor que el dato del nodo actual, recursivamente inserta en el subárbol derecho.
    }
}

void ArbolBinario::insertarElemento(Question question)
{
    insertarElemento(raiz, question);
}

ArbolBinario::Nodo* ArbolBinario::buscarElemento(Nodo* nodo, Question question) {

    if (nodo == nullptr || nodo->question.getId() == question.getId() ){
        return nodo;
    }
    else if (question.getId()<nodo->question.getId()) {
       
       return buscarElemento(nodo->left, question);
    }
    else {
        
        return buscarElemento(nodo->right, question);
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

void ArbolBinario::hacerPregunta() {
    Nodo* nodoActual = raiz;
    cout << "Bienvenido al chatbot del examen 3 de la Universidad Latina" << endl;
    while (nodoActual != nullptr and nodoActual->question.getIsQuestion() == true) {
        cout << nodoActual->question.getQuestion() << " (si/no): ";
        string respuesta;
        cin >> respuesta;

        if (respuesta == "si") {
            nodoActual = nodoActual->right;
        }
        else if (respuesta == "no") {
            nodoActual = nodoActual->left;
        }
        else {
            cout << "Respuesta inválida. Por favor, responde con 'si' o 'no'." << std::endl;
        }

        
    }if (nodoActual != nullptr) {
        cout << nodoActual->question.getQuestion() << endl;

    }
    else {
        cout << "No hay respuestas para tu respuesta " << endl;
    }
    cout << "Gracias por usar el chat bot!" << endl;

    cout << "¡Fin del chat!" << std::endl;
}






