/*
 *	Esse é um programa que verifica a abertura e o fechamento de parenteses, 
 *  colchetes, e chaves de uma expressão: se estão faltando, se estão em excesso, 
 *  como também se estão desordenados;  
 */


#include <iostream>
#include "node_type.h"
#include "stack.h"

using namespace std;

int main() {
	ItemType character;
	Stack stack;
	ItemType stackItem;

	cout << "\nDigite uma expressao com parenteses, colchetes, ou chaves." << endl;
	cin.get(character);
	
	bool isMatched = true;
	while (isMatched && character != '\n') {
		if (character == '{' || character == '(' || character == '[') {
			stack.push(character);
		}
		if (character == '}' || character == ')' || character == ']') {
			if (stack.isEmpty()) {
				isMatched = false;
			} else {
				stackItem = stack.pop();
				isMatched = ((character == '}' && stackItem == '{')
							 || (character == ')' && stackItem == '(')
							 || (character == ']' && stackItem == '['));
			}
		}
		cin.get(character);
	}

	if (isMatched && stack.isEmpty()) {
		cout << "A expressao esta bem formada \n";
	} else {
		cout << "A expressao esta mal formada \n";
	}
}
