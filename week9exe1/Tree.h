#pragma once
#include <iostream>
using namespace std;
#include "QueueVector.h"
#include "Queue.h"

//-----------------------------------
// class Tree (Binary Trees)
// process nodes in Pre/In/Post order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	// inner class Node
	// a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* parent;
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) , parent(NULL){}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	}; //end of Node class
	//data member of tree
	Node* root;
	Node* searchNode(T value, Node* current);
	
public:
	void breadthScan();
	void reflect();
	int height();
	Tree() { root = NULL; } // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
private:
	//private function for not give acsses to user
	void clear(Node* current);
	void preOrder(Node* current);
	void inOrder(Node* current);
	void postOrder(Node* current);
	int height(Node* current);
	void reflect(Node* current);
	
};



//----------------------------------------------------------
// class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{ // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}
template <class T>
int Tree<T>::isEmpty() const
{
	return root == NULL;
}
// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{ // visit Node, left child, right child
	if (current)
	{ // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}
// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{ // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}
// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{ // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
//"פונקציות" חדשות
template<class T>
/*inline*/ int Tree<T>::height()
{
	return height(root);
}
template<class T>
/*inline*/ int Tree<T>::height(Node* current)
{
	if (current == nullptr)
		return -1;
	int hLeft = height(current->left);
	int hright = height(current->right);
	if (hLeft > hright)
		return hLeft + 1;
	else
		return hright + 1;
}
template<class T>
inline void Tree<T>::reflect(Node* current)
{
	if (current == NULL)
		return;
	reflect(current->left);
	reflect(current->right);
	Node* temp = current->left;
	current->left = current->right;
	current->right = temp;
	
}


template<class T>
typename Tree<T>::Node* Tree<T>::searchNode(T value, Node* current)
{
	 if (current == NULL)
		 return NULL;
	 if (current->value == value)
		 return current;
	 if (current->value > value)
	 {
		return this->searchNode(value, current->left);
	 
	 } 
	 if(current->value <value)
		 return this->searchNode(value,current->right);
	
}

template<class T>
inline void Tree<T>::breadthScan()
{
	Queue <Node*> * queue = new QueueVector<Node*>(10);
	if (root == NULL)
		return;
	queue->enqueue(root);
	while (!queue->isEmpty())
	{
		Node* temp = queue->dequeue();
		cout << temp->value << " ";
		if (temp->left != nullptr)
			queue->enqueue(temp->left);
		if(temp->right!=nullptr)
			queue->enqueue(temp->right);
	}

}
template<class T>
inline void Tree<T>::reflect()
{
	reflect(root);
}