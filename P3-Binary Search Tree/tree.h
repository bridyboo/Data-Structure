// Matthew Brian Darmadi
// p3.cpp
//11/2/2018

#ifndef TREE_H
#define TREE_H	

#include "pch.h"
#include <iostream>

struct Node;

class tree
{
public:
	tree(); // default constructor
	//void clear(); // calls destructor;
	~tree(); // calls destructor
	tree(const tree& head); // calls copyConstructor
	//bool overloadedAssignmentOperator(tree &aTree); // calls equalsTo
	void operator= (const tree& head); //oao
	void insert(int key); // calls insertInOrder
	bool find(int key); //calls findkey
	int findMin();// calls findMinKey
	int findMax(); // calls findMaxKey
	int height(); // calls treeHeight
	void print(); // calls printPre
	void printIn(); // calls printInOrder
	void removeKey(int key); // calls removeAnyKey

private:
	bool equalsTo(Node* head); // compares 2 trees
	void copyConstructor(Node* head, tree& aTree); // deep copy an existing tree
	void insertInOrder(Node*&, int key); // inserts roots in order
	bool findKey(Node* head, int key); // returns a bool whether a key is in the tree
	int findMinKey(Node* head); // returns the int value of the lowest int in the tree
	int findMaxKey(Node* head); // return the int vaalue of the highest int in the tree
	int treeHeight(Node* head); // return the int of the height of the tree
	void printPre(Node* head); // traverse the tree in  pre-order and prints out 
	void printInOrder(Node* head);// traverse the tree iteratively in InOrder and prints out
	Node* removeAnyKey(Node* head, int key); // removes a specific key from the tree
	void destructor(Node* head); //deletes the whole binary tree

	Node* root;
};


#endif // !TREE_H