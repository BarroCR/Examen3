#include "ArbolBinario.h"

ArbolBinario::ArbolBinario() : raiz(nullptr) {

}

ArbolBinario::~ArbolBinario() {

}



void ArbolBinario::insertarElemento(Nodo*& nodo, int id, string question, int parent, bool value)
{
    if (nodo == nullptr) {
        nodo = new Nodo(id, question, parent, value);
    }
    else if ((parent == -1 && nodo->id == 0) || nodo->id == parent) { // Si el ID del nodo actual es 0 y el ID del padre es -1, o si el ID del nodo actual coincide con el ID del padre
        // El nodo actual es el nodo padre buscado
        if (value) {
            nodo->left = new Nodo(id, question, parent, value);
        }
        else {
            nodo->right = new Nodo(id, question, parent, value);
        }
    }
    else if (parent < nodo->id) {
        insertarElemento(nodo->left, id, question, parent, value);
    }
    else {
        insertarElemento(nodo->right, id, question, parent, value);
    }
}


void ArbolBinario::insertarElemento(int id, string question, int parent, bool value)
{
    Nodo* parentNode = buscarElemento(raiz, parent);
    if (parentNode != nullptr) {
        insertarElemento(parentNode, id, question, parent, value);
    }
    else {
        cout << "Nodo padre no encontrado. Insertando como nodo raíz." << endl;
        insertarElemento(raiz, id, question, parent, value);
    }
}




ArbolBinario::Nodo* ArbolBinario::buscarElemento(Nodo* nodo, int id) {
    if (nodo == nullptr || nodo->id == id) {
        return nodo;
    }

    cout << "Recorriendo nodo: " << nodo->id << endl; // Impresión para depuración

    if (id < nodo->id) {
        return buscarElemento(nodo->left, id);
    }
    else {
        return buscarElemento(nodo->right, id);
    }
}

ArbolBinario::Nodo* ArbolBinario::buscarElemento(int parentValue) {
    Nodo* resultado = buscarElemento(raiz, parentValue);
    
    if (resultado != nullptr) {
        

        return raiz;
    }
    else {
        

        return nullptr;
    }

}







