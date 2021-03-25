//
// Created by Matthew Brian on 11/13/2018.
//
#include "pch.h"
#ifndef HW4_HEAP_H
#define HW4_HEAP_H
#include <iostream>

struct Node;

class heap
{
public:
	const int defSIZE = 15;

	heap(); // default constructor

	heap(int size); // constructor

	heap(const heap& aheap); //copy constructor

	~heap(); // destructor

	void percolateUp(int hole); // to percolate up

	void insert(int key); // inserts a new Node

	void resize(); // resizes the heap

	void flush(int key); // removes all instance of an int and restores order
		 
	void removeMin(); // removes min int from heap
	// prints both old and new data

	bool isEmpty(); //checks if empty

private:

	Node **array; 
	int size;
	int currsize;

};

#endif //HW4_HEAP_H
