#include <iostream>
#include "stack.h"

using namespace std;

int main() {
	Stack stack;
	ItemType character;		// o mesmo que ~char character~
	ItemType stackItem;		// o mesmo que ~char stackItem~
	
	cout << "Escreva alguma coisa;" << endl;
	cin.get(character); 
	while (character != '\n') {
		stack.push(character);
		cin.get(character);
	}
	while (!(stack.isEmpty())) {
		stackItem = stack.pop();
		cout << stackItem;
	}
	cout << endl;
}
