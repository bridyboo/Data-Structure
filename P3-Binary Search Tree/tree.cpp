// Matthew Brian Darmadi
// tree.cpp
// 2/14/2019

#include "pch.h"
#include "tree.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;


	Node(int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

//----------public------------------
tree::tree()
{
	root = nullptr;
}

tree::~tree()
{
	Node *current = root;
	while (current->left != NULL) {
		Node *garbage = current;
		current = current->left;
		delete garbage;
		current = current->right;
	}
}
tree::tree(const tree &aTree)
{
	//aTree.insert(this->root->data);
	this->insert(aTree.root->data);
}

void tree::operator=(const tree& aTree)
{
	return;
}
void tree::insert(int key)
{
	insertInOrder(root, key);
}


bool tree::find(int key)
{
	return findKey(root, key);
}

int tree::findMin()
{
	return findMinKey(root);
}

int tree::findMax()
{
	return findMaxKey(root);
}

int tree::height()
{
	return treeHeight(root);
}

void tree::print()
{
	return printPre(root);
}
void tree::printIn()
{
	return printInOrder(root);
}

void tree::removeKey(int key)
{
	removeAnyKey(root, key);
	return;
}




//----- private------------------------
void tree::insertInOrder(Node*& head, int key)
{
	if (head == nullptr)
	{
		head = new Node(key);
	}
	else if (key == head->data)
	{
		return;
	}
	else if (key > head->data)
	{
		insertInOrder(head->right, key);
	}
	else if (key < head->data)
	{
		insertInOrder(head->left, key);
	}
}

bool tree::findKey(Node* head, int key)
{
	if (head == nullptr)
		return false;
	if (head->data == key)
		return true;

	if (head->data < key)
	{
		findKey(head->right,key);
	}

	findKey(head->left, key);

	
}
int tree::findMinKey(Node* head)
{

	if (head->left == nullptr)
	{
		return head->data;
	}
	else
		return findMinKey(head->left);

}


int tree::findMaxKey(Node* head)
{
	if (head->right == nullptr)
		return head->data;
	else

		return findMaxKey(head->right);


}


int tree::treeHeight(Node* head)
{
	if (head == nullptr)
		return 1;
	else
	{
		int left = treeHeight(head->left);
		int right = treeHeight(head->right);
		if (left > right)
			return left = 1 + left;
		else
			return right = 1 + right;
	}
}


void tree::printPre(Node* head)
{
	if (head == nullptr)
	{
		return;
	}
	cout << head->data << endl;
	printPre(head->left);
	printPre(head->right);

}


void tree::printInOrder(Node* head)
{
	Node* temp = head;
	stack<Node*> head_stack;

	while (temp != nullptr || head_stack.empty() == false)
	{
		while (temp != nullptr)
		{
			head_stack.push(temp);
			temp = temp->left;
		}
		temp = head_stack.top();
		head_stack.pop();

		cout << temp->data << endl;

		temp = temp->right;
	}

}


Node* minValNode(Node* head)
{
	Node* temp = head;

	if (temp->left != nullptr)
		minValNode(temp->left);

	return temp;
}
Node* findMaxNode(Node* root)
{
	
	if (root->left == NULL) 
		return root;
	else
	
		return findMaxNode(root->left);
}


Node* tree::removeAnyKey(Node* root, int data)
{
	//base case when not found or found then recursion breaks

	if (root == NULL) return root;
	if (root->data > data) root->left = removeAnyKey(root->left, data);
	else if (root->data < data) root->right = removeAnyKey(root->right, data);
	else
	{
		//when the node to be deleted is found
		//Four possibilities

		//case1: When the node to be deleted has no children
		
		//case2: When the node to be deleted has ONLY LEFT child
		if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		//case3: When the node to be deleted has ONLY RIGHT child
		else if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		//case4: When the node to be deleted has TWO children

		
		Node* maxNode = findMaxNode(root->right);//finding the maximum in LEFT sub-tree
		root->data = maxNode->data; //Overwriting the root node with MAX-LEFT
		root->right = removeAnyKey(root->right, maxNode->data);//deleted the MAX-LEFT node
		
		
	}
	return root;
}

void tree::copyConstructor(Node* head, tree& aTree)
{
	if (head == nullptr)
	{
		return;
	}
	else {
		copyConstructor(head->left, aTree);
		copyConstructor(head->right, aTree);
		aTree.insertInOrder(this->root, this->root->data);
	}
}

void tree::destructor(Node* head)
{
	if (head == nullptr)
	{
		return;
	}
	else {
		destructor(head->left);
		destructor(head->right);
		delete head;
	}
}

bool tree::equalsTo(Node* head)
{

	if (head == nullptr)
	{
		return false;
	}

	equalsTo(this->root->left);
	equalsTo(this->root->right);
	equalsTo(head->left);
	equalsTo(head->right);
	if (root->data != head->data)
	{
		return false;
	}
	return true;
}
