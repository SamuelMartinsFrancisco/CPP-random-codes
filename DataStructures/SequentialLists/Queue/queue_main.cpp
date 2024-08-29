#include <iostream>
#include "queue.h"
#include "item_type.h"

using namespace std;

int main() {
	Queue queue;
	ItemType character;
	ItemType queueChar;
	
	cout << "Escreva alguma coisa: " << endl;
	cin.get(character);
	while (character != '\n' and !queue.isFull()) {
		queue.enqueue(character);
		cin.get(character);
	}
	while (!queue.isEmpty()) {
		queueChar = queue.dequeue();
		cout << queueChar << " - ";
	}
	cout << endl;
}
