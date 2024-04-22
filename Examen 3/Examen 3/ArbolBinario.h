#include"std.h"
class ArbolBinario {

private:
    struct Nodo {
        int id;
        string question; 
        int parent;
        bool value; //true izquierda , false derecha 

        Nodo* left;
        Nodo* right;

        Nodo(int  id, string question, int parent, bool value) : id(0), question(""), parent(0), value(NULL), left(nullptr), right(nullptr) {}
    };

    Nodo* raiz;
    void insertarElemento(Nodo*& nodo, int id, string question, int parent, bool value);
    Nodo* buscarElemento(Nodo* nodo, int id);
  
public:
    ArbolBinario();
    ~ArbolBinario();
    void insertarElemento(int id, string qustion, int parent, bool value);
    Nodo* buscarElemento(int parentValue);

    
};



