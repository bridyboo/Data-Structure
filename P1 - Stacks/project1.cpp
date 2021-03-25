//Matthew Brian Darmadi
//Homework 1

#include "pch.h"
#include <iostream>
#include "stack.h"
using namespace std;


stack::stack()
{
	array = new int[defSIZE];
	size = defSIZE;
	top = -1;
}
stack::stack(int size)
{
	array = new int[size];
	this->size = size;
	top = size - 1;
}
stack::stack(const stack &s1)
{
	size = s1.size;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = s1.array[i];
	}

}
stack::~stack()
{
	delete[] array;
}
bool isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
void stack::push(int prime)
{
	if (isEmpty())
		//cout << "stack Overflow \n";
		return;
	if (isFull())
	{
		double newSize = size * 1.5;
		size = (int)newSize;
		int *newStack = new int[size];
		for (int i = 0; i < size; i++)
		{
			newStack[i] = array[i];
		}
		array = newStack;
	}
	if (isPrime(prime))
	{
		++size;
		array[++top] = prime;
	}
	else
		//cout << "doesn't accept non prime number \n";
		return;
}
int stack::pop()
{
	if (isEmpty())
	{
		//cout << "stack is empty\n";
		return 0;
	}
	size--;
	int pop = array[top--];
	//cout << "removed " << pop << " from stack \n";
	return pop;

}
int stack::peek()
{
	if (isEmpty())
	{
		//cout << "stack is Empty \n";
		return 0;
	}
	int peek = array[top];
	//cout << "top is now " << peek <<endl; 
	return peek;
}
int stack::getTop()
{
	return top;
}
bool stack::isEmpty()
{
	if (top < 0)
	{

		return true;
	}
	return false;
}
bool stack::isFull()
{
	if (size == top + 1)
		return true;
	return false;
}
