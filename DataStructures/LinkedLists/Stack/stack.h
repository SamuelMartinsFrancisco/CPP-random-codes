#ifndef STACK_H
#define STACK_H

#include "node_type.h"

class Stack {
	public:
		Stack();
		~Stack();
		bool isEmpty() const;
		bool isFull() const;
		void print() const;
		void push(ItemType);
		ItemType pop();
	
	private:
		NodeType *structure;
};

#endif
