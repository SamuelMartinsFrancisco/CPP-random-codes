#ifndef QUEUE_H
#define QUEUE_H

#include "node_type.h"

class Queue {
	public: 
		Queue();
		~Queue();
		bool isEmpty() const;
		bool isFull() const; 
		void print() const;
		//
		void enqueue(ItemType);
		ItemType dequeue();
	private:
		NodeType *front;	// frente da fila
		NodeType *rear;		// trás da fila
		
};

#endif
