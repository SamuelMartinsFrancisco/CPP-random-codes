#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
    private:
        int ra;
        string nome;
    public:
        Aluno();
        Aluno(int ra, string nome);
        string getName() const;
        int getRa() const;
};

#endif