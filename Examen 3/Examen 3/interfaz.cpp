#include "interfaz.h"

void interfaz::menu()
{

    ArbolBinario arbol;
    Question* pregunta;
    ifstream fin("Preguntas.csv", ios::in); // Abrir el archivo en modo lectura
    list<Question*> questionList;
    if (!fin) {
        cout << "Unable to open file";
    }

    list<vector<string>> lista; // Una lista de vectores para almacenar cada línea dividida
    string line;
    

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

    bool siono;
    

    // Iterar sobre la lista de vectores
    for (const auto& vec : lista) { // Acceso a cada vector en la lista


        sAuxID = vec[0];
        stringstream(sAuxID) >> auxID;
        preg = vec[1];
        siono = (vec[2] == "true") ? true : false;

       /// cout << auxID << preg  << endl;

        pregunta = new Question(auxID,preg,siono);
        
        arbol.insertarElemento(*pregunta);

    }
    

    fin.close(); // Cerrar el archivo



  
    arbol.hacerPregunta();












}
