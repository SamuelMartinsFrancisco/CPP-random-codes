#include <iostream>
#include <cstddef>
#include "search_tree.h"

using namespace std;

void SearchTree::destroyTree(NodeType *&tree) {
    if (tree != NULL) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

bool SearchTree::isEmpty() const {
    return root == NULL;
}

bool SearchTree::isFull() const {
    NodeType *location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch(bad_alloc exception) {
        return true;
    }
}

void SearchTree::retrieveAluno(NodeType *tree,
                               Aluno &aluno,
                               bool &found) const {
    if (tree == NULL) {
        found = false;
    }

    else if (aluno.getRa() < tree->aluno.getRa()) {
        retrieveAluno(tree->left, aluno, found);
    }

    else if (aluno.getRa() > tree->aluno.getRa()) {
        retrieveAluno(tree->right, aluno, found);
    }

    else {
        aluno = tree->aluno;
        found = true;
    }
}

void SearchTree::insertAluno(NodeType *&tree, Aluno aluno) {
    if (tree == NULL) {
        tree = new NodeType;
        tree->right = NULL;
        tree->left = NULL;
        tree->aluno = aluno;
    }
    else if (aluno.getRa() < tree->aluno.getRa()) {
        insertAluno(tree->left, aluno);
    }
    else {
        insertAluno(tree->right, aluno);
    }
}

void SearchTree::printPreOrder(NodeType *tree) const {
    if (tree != NULL) {
        cout << tree->aluno.getName() << " , ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void SearchTree::printInOrder(NodeType *tree) const {
    if (tree != NULL) {
        printInOrder(tree->left);
        cout << tree->aluno.getName() << " , ";
        printInOrder(tree->right);
    }
}

void SearchTree::printPostOrder(NodeType *tree) const {
    if (tree != NULL) {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << tree->aluno.getName() << " , ";
    }
}

void SearchTree::deleteNode(NodeType *&tree) {
    Aluno data;
    NodeType *tempPointer;
    tempPointer = tree;

    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPointer;
    }
    else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPointer;
    }
}

void SearchTree::getSuccessor(NodeType *tree, Aluno &data) const {
    tree = tree->right;
    while (tree->left != NULL) {
        tree = tree->left;
    }
    data = tree->aluno;
}

void SearchTree::deleteAluno(NodeType *&tree, int aluno) {
    if (aluno < tree->aluno.getRa()) {
        deleteAluno(tree->left, aluno);
    } 
    else if (aluno > tree->aluno.getRa()) {
        deleteAluno(tree->right, aluno);
    }
    else if (aluno == tree->aluno.getRa()) {
        deleteNode(tree);
    }
}

void SearchTree::deleteNode(NodeType *&tree) {
    Aluno data;
    NodeType *tempPointer;
    tempPointer = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPointer;
    }
    else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPointer;
    }
    else {
        getSuccessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->right, data); // ?
    }
}