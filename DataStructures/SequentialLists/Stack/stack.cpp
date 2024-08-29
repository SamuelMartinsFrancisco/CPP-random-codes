// implementação da classe

#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
	length = 0;
	structure = new ItemType[MAX_ITEMS];	// o mesmo que ~new char[MAX_ITEMS]~
}

Stack::~Stack() {
	delete [] structure;
}

bool Stack::isEmpty() const {
	return (length == 0);
}

bool Stack::isFull() const {
	return (length == MAX_ITEMS);
}

void Stack::push(ItemType item) {
	if(!isFull()) {
		structure[length] = item;
		length++;
	} else {
		throw "A pilha já está cheia :0";
	}
}

ItemType Stack::pop() {
	if(!isEmpty()) {
		ItemType rmvd_item = structure[length-1];
		length--;
		return rmvd_item;
	} else {
		throw "A pilha já está vazia :0";
	}
}

void Stack::print() const {
	cout << "Pilha = ";
	for (int i = 0; i < length; i++) {
		cout << structure[i] << '\n';
	}
	cout << endl;
	
}

