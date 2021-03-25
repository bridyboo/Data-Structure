// stack.h
// Matthew Brian Darmadi

#ifndef STACK_H
#define STACK_H


#include "pch.h"
#include <iostream>
class stack
{
public:
	const int defSIZE = 30;
	stack(); // default constructor
	stack(int size); //  constructor
	stack(const stack &s1); //copy constructor
	~stack(); // destructor
	void push(int prime); // to push a prime integer into the stack
	int pop();
	//to take out a integer from the top of the stack
	//returns and removes the int at the top of the stack

	int peek();
	//to see what's at the top of the stack
	//returns the int at the top of the stack
	int getTop();
	//returns the index of top
	bool isEmpty();
	//returns true if empty

	bool isFull();
	//returns true if full

private:
	int *array;
	int top;
	int size;
};

#endif // STACK_H