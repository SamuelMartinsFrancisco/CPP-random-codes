#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	char character;
	Queue queue;

	queue.enqueue('B');
	queue.enqueue('a');
	queue.enqueue('l');
	queue.enqueue('e');
	queue.enqueue('i');
	queue.enqueue('a');
	queue.print();

	while (!queue.isEmpty()) {
		queue.dequeue();
	}
}
