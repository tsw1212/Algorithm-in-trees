//#pragma once
//#include "Tree.h"
//#include <iostream>
//using namespace std;
//template<class T>
//class SearchTree : public Tree<T>
//{
//public:
//	void deleteDuplicates();
//	typename Tree<T>::Node* successorMe(T val);
//	T successor(T val);
//	void remove(T val);
//	void add(T value);
//	bool search(T value)
//	{
//		return search(Tree<T>::root, value);
//	}
//private:
//	void add(typename Tree<T>::Node* current, T val);
//	bool search(typename Tree<T>::Node* current, T val);
//	void scan(typename Tree<T>::Node* current);
//	void findDuplicates(typename Tree<T>::Node* current, T val);
//	void removeMe(typename Tree<T>::Node* current);
//};
//
//template <class T>
//void SearchTree<T>::add(T val)
//{
//	// add value to binary search tree
//	if (!Tree<T>::root)
//	{
//		Tree<T>::root = new typename Tree<T>::Node(val);
//		return;
//	}
//	add(Tree<T>::root, val);
//}
//template <class T>
//void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
//{
//	if (current->value < val)
//	{
//		if (!current->right)
//		{
//			current->right = new typename Tree<T>::Node(val);
//			(current->right)->parent = current;
//			return;
//		}
//		else add(current->right, val);
//	}
//	else
//		if (!current->left)
//		{
//			current->left = new typename Tree<T>::Node(val);
//			(current->left)->parent = current;
//			return;
//		}
//		else add(current->left, val);
//}
//
//
//template <class T>
//bool SearchTree<T>::search(typename Tree<T>::Node * current, T val)
//{
//	// see if argument value occurs in tree
//	if (!current)
//		return false; // not found
//	if (current->value == val)
//		return true;
//	if (current->value < val)
//		return search(current->right, val);
//	else
//		return search(current->left, val);
//}
//
//
//
//
//
//
//template<class T>
//inline typename Tree<T>::Node* SearchTree<T>::successorMe(T val)
//{
//	typename Tree<T>::Node* p = (*this).searchNode(val, Tree<T>::root);
//		if (p == NULL)
//			throw "no successor";
//	if (p->right != nullptr)
//	{
//		p = p->right;
//		while (p->left!=nullptr)
//		{
//			p = p->left;
//		}
//		return p;
//	}
//	typename Tree<T>::Node* p1 = p->parent;
//	while (p1 != NULL && p == p1->right)
//	{
//		p = p1;
//		p1 = p->parent;
//	}
//	return p1;
//}
//
//template<class T>
//inline void SearchTree<T>::remove(T val)
//{
//	typename Tree<T>::Node* temp;
//		temp = (*this).searchNode(val, Tree<T>::root);
//		removeMe(temp);
//		/*if (temp->right == NULL && temp->left == NULL)
//		{
//			if ((temp->parent)->right == temp)
//			{
//				(temp->parent)->right = nullptr;
//			}
//			else
//				(temp->parent)->left = nullptr;
//			delete temp;
//			return;
//		}
//		if (temp->right != nullptr && temp->left == NULL)
//		{
//			if ((temp->parent)->right == temp)
//			{
//				(temp->parent)->right = temp->right;
//				(temp->right)->parent = temp->parent;
//			}
//			else
//			{
//				(temp->parent)->left = temp->right;
//				(temp->left)->parent = temp->parent;
//			}
//				
//			delete temp;
//			return;
//		}
//		if (temp->right == nullptr && temp->left != NULL)
//		{
//			if ((temp->parent)->right == temp)
//			{
//				(temp->parent)->right = temp->left;
//				(temp->right)->parent = temp->parent;
//			}
//			else
//			{
//				(temp->parent)->left = temp->left;
//				(temp->left)->parent = temp->parent;
//			}
//				
//			delete temp;
//			return;
//		}
//		else
//		{
//			typename Tree<T>::Node* p =this->successorMe(temp->value);
//			T x = p->value;
//			remove(p->value);
//			temp->value = x;
//			
//		}*/
//}
//
//template<class T>
//inline void SearchTree<T>::deleteDuplicates()
//{
//	scan(Tree<T>::root);
//}
//template<class T>
//inline void SearchTree<T>::scan(typename Tree<T>::Node* current)
//{
//	if (current == NULL)
//		return;
//	if(current->left!=nullptr)
//		findDuplicates(current->left, (current->left)->value);
//	scan(current->left);
//	scan(current->right);
//}
//
//template<class T>
//inline void SearchTree<T>::findDuplicates(typename Tree<T>::Node* current, T val)
//{
//	if (current == nullptr)
//		return ;
//	if(current->left!=nullptr)
//	findDuplicates(current->left, val);
//	if (current->right != nullptr)
//	findDuplicates(current->right, val);
//	if (current->value == val)
//		removeMe(current);
//
//}
//
//template<class T>
//inline T SearchTree<T>::successor(T val) {
//	typename Tree<T>::Node* temp = this->successorMe(val);
//		if(temp==nullptr)
//			throw "no successor";
//	return(temp->value);
//}
//
//
//template<class T>
//inline void SearchTree<T>::removeMe(typename Tree<T>::Node* temp)
//{
//	if (temp->right == NULL && temp->left == NULL)
//	{
//		if ((temp->parent)->right == temp)
//		{
//			(temp->parent)->right = nullptr;
//			delete temp;
//			return;
//		}
//		else
//		{
//			(temp->parent)->left = nullptr;
//			delete temp;
//			return;
//		}
//		return;
//	}
//	if (temp->right != NULL && temp->left == NULL)
//	{
//		if ((temp->parent)->right == temp)
//		{
//			(temp->parent)->right = temp->right;
//			(temp->right)->parent = temp->parent;
//			delete temp;
//			return;
//		}
//		if((temp->parent)->left == temp)
//		{
//			(temp->parent)->left = temp->right;
//			(temp->right)->parent = temp->parent;
//			delete temp;
//			return;
//		}
//		return;
//	}
//	if (temp->right == nullptr && temp->left != NULL)
//	{
//		if ((temp->parent)->right == temp)
//		{
//			(temp->parent)->right = temp->left;
//			(temp->left)->parent = temp->parent;
//			delete temp;
//			return;
//		}
//		if((temp->parent)->left == temp)
//		{
//			(temp->parent)->left = temp->left;
//			(temp->left)->parent = temp->parent;
//			delete temp;
//			return;
//		}
//		return;
//	}
//	else
//	{
//		typename Tree<T>::Node* p = this->successorMe(temp->value);
//		T x = p->value;
//		removeMe(p);
//		temp->value = x;
//
//	}
//}
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;
template<class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	bool search(T value)
	{
		return search(Tree<T>::root, value);
	}
	typename Tree<T>::Node* successorNode(T val);
	T successor(T val);
	void remove(T val);
	void deleteDuplicates();
private:
	void scanTree(typename Tree<T>::Node* current);
	void searchDuplicate(typename Tree<T>::Node* current, T val);
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	void removeMe(typename Tree<T>::Node* temp);
};
template <class T>
void SearchTree<T>::deleteDuplicates() {
	scanTree(Tree<T>::root);
}
template <class T>
inline T SearchTree<T>::successor(T val) {
	typename Tree<T>::Node* retured_value = this->successorNode(val);
	if (retured_value == nullptr) {
		throw "no successor";
	}
	return retured_value->value;
}
template <class T>
inline void SearchTree<T>::scanTree(typename Tree<T>::Node* current) {
	if (current == nullptr) {
		return;
	}
	if (current->left) {
		searchDuplicate(current->left, current->value);
	}
	scanTree(current->left);
	scanTree(current->right);
}
template <class T>
void SearchTree<T>::removeMe(typename Tree<T>::Node* temp) {
	if (temp->right == nullptr && temp->left == nullptr) {
		if (temp->parent->right == temp) {
			temp->parent->right = nullptr;
			delete temp;
			return;
		}
		else {
			temp->parent->left = nullptr;
			delete temp;
			return;
		}
	}
	if ((temp->right && !temp->left)) {
		if (temp->parent->right == temp) {
			temp->parent->right = temp->right;
			temp->right->parent = temp->parent;
			delete temp;
			return;
		}
		if (temp->parent->left == temp) {
			temp->parent->left = temp->right;
			temp->right->parent = temp->parent;
			delete temp;
			return;
		}
	}
	if ((temp->left && !temp->right)) {
		if (temp->parent->right == temp) {
			temp->parent->right = temp->left;
			temp->left->parent = temp->parent;
			delete temp;
			return;
		}
		if (temp->parent->left == temp) {
			temp->parent->left = temp->left;
			temp->left->parent = temp->parent;
			delete temp;
			return;
		}
	}
	else {
		typename Tree<T>::Node* temp2 = this->successorNode(temp->value);
		T value = temp2->value;
		removeMe(temp2);
		temp->value = value;
	}

}
template <class T>
void SearchTree<T>::searchDuplicate(typename Tree<T>::Node* current, T val) {
	if (current == nullptr) {
		return;
	}
	if (current->left) {
		searchDuplicate(current->left, val);
	}
	if (current->right) {
		searchDuplicate(current->right, val);
	}
	if (current->value == val) {
		removeMe(current);
	}
}
template <class T>
inline void SearchTree<T>::remove(T val) {
	typename Tree<T>::Node* temp;
	temp = this->searchNode(val, Tree<T>::root);
	removeMe(temp);
}
template <class T>
typename Tree<T>::Node* SearchTree<T>::successorNode(T val) {
	typename Tree<T>::Node* temp = this->searchNode(val, Tree<T>::root);
	if (temp == nullptr) {
		throw "no successor";
	}
	if (temp->right != nullptr) {
		temp = temp->right;
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
	}
	else {
		typename Tree<T>::Node* temp2 = temp->parent;
		while (temp2 != nullptr && temp == temp2->right) {
			temp = temp2;
			temp2 = temp->parent;
		}
		return temp2;
	}
}
template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}
template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			current->right->parent = current;
			return;
		}
		else add(current->right, val);
	else
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			current->left->parent = current;
			return;
		}
		else add(current->left, val);
}
template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false; // not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

