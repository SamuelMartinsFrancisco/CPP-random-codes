#ifndef ALUNO_H
#define ALUNO_H

#include <string>

using namespace std;

class Aluno {
    private: 
        int ra;
        string name;
    public:
        Aluno();
        Aluno(int ra, string name);
        string getName() const;
        int getRa() const;
};

#endif