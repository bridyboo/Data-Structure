// Matthew Brian Darmadi 
// P2 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void insertInOrder(Node*& h, int data)
{
	if (h == nullptr || h->data > data)
	{
		Node* head = new Node;
		head-> data = data;
		head->next = h;
		h = head;
	}
	Node* temp = h; // pointer to head
	Node* ans = new Node;
	ans->data = data;
	while (temp->next != nullptr && temp->next->data <= data){
		temp = temp->next;
	}
	ans->next = temp->next;
	temp->next = ans;
	return;
}

void deleteNode(Node*& h, string type)
{
	if (h == nullptr || h->data == data)
	{
		
	}
}
int main()
{

}

