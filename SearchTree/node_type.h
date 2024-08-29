#ifndef NODE_TYPE_H
#define NODE_TYPE_H

#include "aluno.h";

struct NodeType {
    Aluno aluno;
    NodeType *left;
    NodeType *right;
};

#endif