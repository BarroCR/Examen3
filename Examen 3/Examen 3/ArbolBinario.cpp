#include "ArbolBinario.h"
#include <fstream>

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
    ofstream archivo("respuestas_chatbot.txt", ios::app);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para guardar las respuestas." << endl;
        return;
    }

    archivo << "Bienvenido al chatbot del examen 3 de la Universidad Latina\n";
    cout << "Bienvenido al chatbot del examen 3 de la Universidad Latina" << endl;

    while (nodoActual != nullptr and nodoActual->question.getIsQuestion() == true) {

        cout << nodoActual->question.getQuestion() << " (si/no): ";
        archivo << nodoActual->question.getQuestion() << " (si/no): ";

        string respuesta;
        cin >> respuesta;

        archivo << respuesta << "\n"; // Guarda la respuesta en el archivo

        if (respuesta == "si") {
            nodoActual = nodoActual->right;
        }
        else if (respuesta == "no") {
            nodoActual = nodoActual->left;
        }
        else {
            cout << "Respuesta inválida. Por favor, responde con 'si' o 'no'." << endl;
        }


    }if (nodoActual != nullptr) {
        cout << nodoActual->question.getQuestion() << endl;
        archivo << nodoActual->question.getQuestion() << "\n"; // Guarda la pregunta final en el archivo

    }
    else {
        cout << "No hay respuestas para tu respuesta " << endl;
        archivo << "No hay respuestas para tu respuesta\n";
    }
    cout << "Gracias por usar el chat bot!" << endl;
    archivo << "Gracias por usar el chat bot!\n";

    cout << "¡Fin del chat!" << endl;
    archivo << "¡Fin del chat!\n\n\n";

    archivo.close();
}






