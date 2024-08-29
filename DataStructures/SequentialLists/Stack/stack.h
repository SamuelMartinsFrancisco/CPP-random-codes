// declaração da classe, e de seus métodos e atributos

#include "item_type.h"

const int MAX_ITEMS = 100;

class Stack {
	private:
		int length;
		ItemType *structure;	// o mesmo que ~char *structure~
		
	public:
		Stack();	// construtor
		~Stack();	// destrutor
		bool isEmpty() const;
		bool isFull() const;
		void print() const;
		
		void push(ItemType);	// o mesmo que ~void push(char)~
		ItemType pop();			// o mesmo que ~char pop()~
};
