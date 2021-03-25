// Matthew Brian Darmadi
// p3.cpp
// 2/14/2019

#include "pch.h"
#include "tree.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>


using namespace std;

int main()
{

	int arr[] = { 45 , 33 , 11, 99, 14, 88, 15, 20 , 13, 1 , 55 , 12
		, 47, 25, 10, 21, 23, 24, 17, 31, 2,2,2 };

	tree* test = new tree();
	cout << "constructing a tree , and inserting an array of preset numbers" << endl
		<< "press enter to start the print (pre-order)" << endl << endl << endl
		<< "{ 10 , 33 , 11, 15, 20 , 13, 1 , 55 , 12"
		<< ", 47, 25, 99, 14, 88, 45, 21, 23, 24, 17, 31, 2, 2, 2}" << endl;

	cin.get();
	for (int i = 0; i < 23; i++)
	{
		test->insert(arr[i]);
	}
	test->print(); cout << endl;

	cin.get();

	cout << "as you can see only one instance of '2' was accepted" << endl
		<< "let's try the in order print" << endl << endl;

	cin.get();

	test->printIn(); //test print inorder
	
	cout << " the output is sorted from min to max" << endl;

	test->print(); //test printpre
	cout << " let's try our find min and max key" << endl;
	cout << " press enter to start" << endl;
	cin.get();

	cout << " max = " <<test->findMax() << endl
		<< " min = " << test->findMin() << endl <<endl;


	cin.get();
	cout << " notice that the first and last integer of the in order list are both here";
	cout << " let's try our 'find specific key'" << endl
		<< " we'll be looking for '99'" << endl
		<< " press enter to start" << endl;
	cin.get();

	cout << "find (0 false / 1 true) =  " << test->find(1111) << endl << endl; //test

	cin.get();

	cout << " let's test our 'find height it should return 11" << endl
		<< " press enter to start" << endl;

	cin.get();

	cout << "height = " << test->height();

	cout << " let's test our delete key " << endl
		<< " we'll delete '10' " << endl;

	cin.get();

	//test->removeKey(10);

	cout << "test copy, overloaded and clear" << endl;
	cin.get();

	test->removeKey(10);
	//test->removeKey(1);
	test->printIn();

	cin.get();
	cout << "that's the end of the prgram";




	return 0;
}
