#include <iostream>
#include "aluno.h"
#include "hash.h"

Hash::Hash(int max) {
    length = 0;
    max_items = max;
    structure = new Aluno[max_items];
}

bool Hash::isFull() const {
    return (length == max_items);
}

int Hash::getLength() const {
    return length;
}

int Hash::getHash(Aluno aluno) {
    return aluno.getRa() % max_items;
}

//////////////////////////////////////////////////////////////////////////////////
// as duas implentações: com e sem tratamento de colisões, estão nos arquivos: 
//      collision_handling.txt  e  no_collision_handling.txt

void Hash::retrieveItem(Aluno &aluno, bool &found) {
    int start_index = getHash(aluno);
    bool keep_looking = true;
    int index = start_index;

    do {
        if ((structure[index].getRa() == aluno.getRa()) || (structure[index].getRa() == -1)) {
                keep_looking = false;
        } else {
            index = (index + 1) % max_items;
        }
    } while ((index != start_index) && keep_looking);

    found = (structure[index].getRa() == aluno.getRa());
    if (found) {
        aluno = structure[index];
    }
}

void Hash::deleteItem(Aluno aluno) {
    int start_index = getHash(aluno);
    bool keep_looking = true;
    int index = start_index;

    do {
        if ((structure[index].getRa() == aluno.getRa()) || (structure[index].getRa() == -1)) {
            keep_looking = false;
        } else {
            index = (index + 1) % max_items;
        }
    } while ((index != start_index) && keep_looking);

    if (structure[index].getRa() == aluno.getRa()) {
        structure[index] = Aluno(-2, "");
        length--;
    }
}

void Hash::insertItem(Aluno aluno) {
    int index;
    index = getHash(aluno);
    
    while (structure[index].getRa() > 0) {
        index = (index + 1) % max_items;
    }
    // atenção: se o vetor estiver cheio a busca não vai terminar

    structure[index] = aluno;
    length++;
}

//////////////////////////////////////////////////////////////////////////////////


void Hash::print() {
    for (int i = 0; i < max_items; i++) {
        cout << i << " - " << 
            structure[i].getRa() <<
            ", " <<
            structure[i].getName() << endl;
    }
}
