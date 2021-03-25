// Matthew Brian Darmadi

#include "pch.h"
#include "heap.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{

	cout << "welcome to my homework 4" << endl
		<< "we will start by initializing h2 with a size of 2" << endl
		<< "and we'll insert and remove 15 ints which would exceed" << endl;

	cout << "press enter to begin..." << endl << endl;
	cin.get();

	srand(time(0));

	heap* h1 = new heap();
	heap* h2 = new heap(2);
	for (int i = 0; i < 15; i++)
	{
		int random = rand() % 30 + 1;
		h2->insert(random);
	}

	for (int j = 1; j < 16; j++)
	{
		h2->removeMin();
	}

	cout << endl << " as you can see even though h2 exceeds its initial size"
		<< " it manages to print and keep more than 2" << endl << endl;

	cin.get();
	cout << " we insert h1 with 2,4,13,14,15,8,6,12,11" << endl;

	cout << " now we remove min"
		<< "  so it should print" << endl
		<< " the lowest which is 2" << endl;

	cin.get();

	h1->insert(2);
	h1->insert(4);
	h1->insert(13);
	h1->insert(14);
	h1->insert(15);
	h1->insert(8);
	h1->insert(6);
	h1->insert(12);
	h1->insert(11);

	//--------------------
	h1->removeMin();
	cin.get();

	

	return 0;
}
