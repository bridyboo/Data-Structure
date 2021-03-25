// Created by Matthew Brian on 11/13/2018.
//
#include "pch.h"
#include <iostream>
#include "heap.h"

using namespace std;

struct Node
{
	int data;
	int newData;

	Node(int data)
	{
		this->data = data; //keeps the original key 
		newData = data; //same like data until changed by prio
	}
};

//------- heap ---------
heap::heap()
{
	array = new Node*[defSIZE];
	size = defSIZE;
	currsize = 0;
}

heap::heap(int size)
{
	array = new Node*[size];
	this->size = size;
	currsize = 0;
}

heap::heap(const heap& aheap)
{
	for (int i = 1; i < this->size; i++)
		this->insert(aheap.array[i]->data);
	
}

heap::~heap()
{
	for (int i = 0; i < this->size; i++)
		delete array[i];

	delete[] array;
}

void heap::insert(int key)
{
	if (currsize == size)
		resize();
	
	currsize += 1;
	int hole = currsize;
	Node* nodeKey = new Node(key);
	array[hole] = nodeKey;
	percolateUp(hole);
}

void heap::percolateUp(int hole)
{
	int location = hole;
	while (location > 1 &&
		array[location]->newData < array[location / 2]->newData){
			Node* temp = array[location / 2];
			array[location / 2] = array[location];
			array[location] = temp;
			location = location / 2;
	}
}
void heap::flush(int key)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i]->newData == key)
		{
			array[i]->newData == 0;
		}
	}
}

bool heap::isEmpty()
{
	if (currsize == 0)
		return true;
	return false;
}
void heap::resize()
{
	double newSize = size * 1.5;
	size = (int)newSize;
	Node** newStack = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		newStack[i] = array[i];
	}
	array = newStack;
}

void heap::removeMin()
{
	int hole = 1; // smallest at the top
	if (array[hole] == nullptr || array[hole]->newData == 0)
		return;

	else{
		int newData = array[hole]->newData;
		int oldData = array[hole]->data;
		Node* temp = array[currsize]; //move newest in heap to temp
		array[currsize] = new Node(0);
		currsize -= 1;
		array[1] = temp; // smallest spot switch with newest temp
		while ((hole * 2 <= currsize && array[hole]->newData > array[hole * 2]->newData)
			|| (hole * 2 + 1 <= currsize && array[hole]->newData > array[hole * 2 + 1]->newData)){
			temp = array[hole];
			if (array[hole]->newData >= array[hole * 2]->newData
				&& array[hole * 2]->newData < array[hole * 2 + 1]->newData){
				array[hole] = array[hole * 2];
				array[hole * 2] = temp;
				hole = hole * 2;
			}

			else{
				array[hole] = array[hole * 2 + 1];
				array[hole * 2 + 1] = temp;
				hole = hole * 2 + 1;
			}
		}
		cout << newData << " ";
	}
}
