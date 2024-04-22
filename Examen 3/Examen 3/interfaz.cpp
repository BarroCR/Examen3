#include "interfaz.h"
void interfaz::menu()
{

    ArbolBinario arbol;
    ifstream fin("Preguntas.csv", ios::in); // Abrir el archivo en modo lectura

    if (!fin) {
        cout << "Unable to open file";
    }

    list<vector<string>> lista; // Una lista de vectores para almacenar cada línea dividida
    string line;
    list<Question> preguntas;

    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> parsedRow;
        string item;

        while (getline(ss, item, ',')) { // Dividir la línea en elementos separados por comas
            parsedRow.push_back(item); // Agregar cada elemento al vector
        }

        lista.push_back(parsedRow); // Agregar el vector a la lista
    }

    fin.close(); // Cerrar el archivo.

    string sAuxID;
    int auxID;
    string preg;
    string sParent;
    int auxParent;
    bool siono;
    

    // Iterar sobre la lista de vectores
    for (const auto& vec : lista) { // Acceso a cada vector en la lista


        sAuxID = vec[0];
        stringstream(sAuxID) >> auxID;
        preg = vec[1];
        sParent = vec[2];
        stringstream(sParent) >> auxParent;
        siono = (vec[3] == "true") ? true : false;

        cout << auxID << preg << auxParent << endl;


        arbol.insertarElemento(auxID, preg, auxParent, siono);

    }
    
    cout << "hola" << endl;
    fin.close(); // Cerrar el archivo


  
   





}
