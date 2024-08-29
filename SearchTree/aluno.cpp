#include "aluno.h"

Aluno::Aluno() {
    this->ra = -1;
    this->name = "";
};

Aluno::Aluno(int ra, string name) {
    this->ra = ra;
    this->name = name;
}

string Aluno::getName() const {
    return name;
}

int Aluno::getRa() const {
    return ra;
}

