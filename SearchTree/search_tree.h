#include <cstddef>
#include "node_type.h"
#include "aluno.h"

class SearchTree {
    private:
        void destroyTree(NodeType *&tree);
        void retrieveAluno(NodeType *tree, 
                           Aluno &item, 
                           bool &found) const;
        void insertAluno(NodeType *&tree, Aluno item);
        void deleteAluno(NodeType *&tree, int item);
        void deleteNode(NodeType *&tree);
        void getSuccessor(NodeType *tree, Aluno &data) const;
        void printTree(NodeType *tree) const;
        void printPreOrder(NodeType *tree) const;
        void printInOrder(NodeType *tree) const;
        void printPostOrder(NodeType *tree) const;
        NodeType *root;
        
    public:
        SearchTree() { root = NULL; }
        ~SearchTree() { destroyTree(root); }
        bool isEmpty() const;
        bool isFull() const;
        void retrieveAluno(Aluno &item, bool &found) const {
            retrieveAluno(root, item, found);
        }
        void insertAluno(Aluno item) { insertAluno(root, item); }
        void deleteAluno(int item) { deleteAluno(root, item); }
        void printPreOrder() const { printPreOrder(root); }
        void printInOrder() const { printInOrder(root); }
        void printPostOrder() const { printPostOrder(root); }
};
/*
    Por que alguns métodos da interface privada se repetem na interface pública?
 */