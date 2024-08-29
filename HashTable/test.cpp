#include <iostream>
#include "hash.h"
#include "aluno.h"

using namespace std;

int main() {
    Hash hash(10);
    
    int ras[7] = {
        12704, 31300, 1234,
        49001, 52202, 65606,
        91234
    };
    string names[7] = {
        "Pedro", "Jonas", "Paulo",
        "Jeremias", "Doug", "Samuel",
        "Samanta"
    };

    for (int i = 0; i < 7; i++) {
        Aluno aluno = Aluno(ras[i], names[i]);
        hash.insertItem(aluno);
    }

    hash.print();
    cout << endl << "########################" << endl;

    // método de busca
    Aluno aluno(12704, "");
    bool found = false;

    hash.retrieveItem(aluno, found);
    cout << aluno.getName() << 
            " -> " << found << endl;
}