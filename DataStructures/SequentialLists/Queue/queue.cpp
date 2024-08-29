#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue() {
	front = 0;
	back = 0;
	structure = new ItemType[MAX_ITEMS];
}

Queue::~Queue() {
	delete [] structure;
}

bool Queue::isEmpty() const {
	return (front == back);
}

bool Queue::isFull() const {
	return (back - front == MAX_ITEMS);
}

void Queue::enqueue(ItemType item) {
	if (!isFull()) {
		structure[back % MAX_ITEMS] = item;
		back++;
	} else {
		throw "A fila já está cheia!";
	}
}

ItemType Queue::dequeue() {
	if(!isEmpty()) {
		front++;
		return structure[(front-1) % MAX_ITEMS];
	} else {
		throw "A fila já está vazia!";
	}
}

void Queue::print() const {
	cout << "Fila = ";
	for (int i = front; i < back; i++) {
		cout << structure[i % MAX_ITEMS];
	}
	cout << endl;
}

/*

Em filas, o único elemento que pode ser removido é o da frente; 
e os novos elementos são inseridos no final da fila;
em um vetor de tamanho predefinido, isso acaba trazendo um efeito engraçado:
a lista vai andando ao longo do vetor, deixando um espaço vazio no início;
para lidar com essa questão, o vetor é imaginado como sendo circular;
o operador de resto permite simular isso;
quando o índice chega na posição final do vetor, a posição seguinte, que ultrapassa seu tamanho
é convertida para a índice inicial, usando o operador de resto (%);
*/
