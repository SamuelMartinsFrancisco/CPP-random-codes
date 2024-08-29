#include <iostream>
#include <cstddef>
#include <new>
#include "node_type.h"
#include "queue.h"

using namespace std;

// Constructor
Queue::Queue() {
	front = NULL;
	rear = NULL;
}

// Destructor
Queue::~Queue() {
	NodeType *tempPointer;
	while (front != NULL) {
		tempPointer = front;
		front = front->next;
		delete tempPointer;
	}
	rear = NULL;
}

// isEmpty
bool Queue::isEmpty() const {
	return (front == NULL);
}

// isFull
bool Queue::isFull() const {
	NodeType *test_item;
	try {
		test_item = new NodeType;
		delete test_item;
		return false;
	} catch(bad_alloc exception) {
		return true;
	}
}

// enqueue
void Queue::enqueue(ItemType new_item) {
	if (!isFull()) {
		NodeType *new_node;
		new_node = new NodeType;	// cria um novo nó, ainda solto
		new_node->info = new_item;
		new_node->next = NULL;
		if (isEmpty()) {
			front = new_node;		// se a fila estiver vazia, o novo nó é o primeiro da fila
		} else {
			rear->next = new_node;	
		}
		rear = new_node;			// se a fila não estiver vazia, o novo nó agora é o último da fila
	} else {
		throw "Epa! A pilha já está cheia";
	}
}

// dequeue
ItemType Queue::dequeue() {
	if(!isEmpty()) {
		NodeType *tempPointer;
		tempPointer = front;
		ItemType item = front->info;
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		delete tempPointer;
		return item;
	} else {
		throw "Epa! A fila já está vazia";
	}
}

// print
void Queue::print() const {
	NodeType *tempPointer = front;
	while (tempPointer != NULL) {
		cout << tempPointer->info;
		if (tempPointer->next != NULL) {
			cout << "-";
		}
		tempPointer = tempPointer->next;
	}
	cout << endl;
	// o método print não está funcionando como deveria
	// endereços de memória errados?
}
