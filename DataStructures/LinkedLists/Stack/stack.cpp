#include <iostream>
#include <cstddef>
#include <new>
#include "stack.h"

using namespace std;

Stack::Stack() {
	structure = NULL;
	// structure é o topo da pilha, que começa vazia
}

Stack::~Stack() {
	NodeType *tempPointer;
	
	while (structure != NULL) {
		tempPointer = structure;		// guarda o ponteiro do topo da pilha
		structure = structure->next;	// define o elemento debaixo como o novo topo
		delete tempPointer; 
	}
	// Enquanto houver um topo na pilha, elemento por elemento é excluído
}

bool Stack::isEmpty() const {
	return (structure == NULL);
}

bool Stack::isFull() const {
	NodeType *test;
	try {
		test = new NodeType;	// tentativa de alocar memória
		delete test;
		return false;			// se der certo a memória não está cheio
	} catch (bad_alloc exception) {
		// o bad_alloc lança erros quando há problemas de alocação de memória
			// ele faz parte do pacote <new>
		return true;
	}
}

void Stack::push(ItemType new_item) {
	if (!isFull()) {
		NodeType *item;
		item = new NodeType;
		item->info = new_item;
		item->next = structure;
		structure = item;
	} else {
		throw "Epa! A pilha já está cheia";
	}
}

ItemType Stack::pop() {
	if (!isEmpty()) {
		NodeType *tempPointer;
		tempPointer = structure;
		ItemType item = structure->info;
		structure = structure->next;
		delete tempPointer;
		return item;
	} else {
		throw "Epa! A pilha ainda está vazia";
	}
}

void Stack::print() const {
	NodeType *tempPointer = structure;
	while (tempPointer != NULL) {
		cout << tempPointer->info;
		tempPointer = tempPointer->next;
	}
	cout << endl;
}
