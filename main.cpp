// DoublyLinkedList.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// This is a node class.
// This class can take custom datatypes and be added to a
// doubly linked list. Each node has a pointer to the next node
// and the previous node.
template<class T>
class DLLNode
{
public:
	DLLNode();
	DLLNode(const T &el, DLLNode *n, DLLNode *p);
	T info;
	DLLNode *next, *prev;
};

// DLLNode default constructor
template<class T>
DLLNode<T>::DLLNode()
{
	next = prev = nullptr;
}


// Constructor
template<class T>
DLLNode<T>::DLLNode(const T &el, DLLNode *n, DLLNode *p) :
info(el), next(n),prev(p)
{
}


// Doubly linked list class
// Each node contains a pointer to the next and previous
// node.
template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();							// Implemented
	void addToDLLTail(const T &el);				// Implemented
	bool deleteFromDLLTail(T &el);				// Implemented
	void print();								// Implemented
	bool insertBefore(T target, T &newItem);	// Implemented
	DLLNode<T> * search(T &target);				// Implemented
	bool DeleteTarget(T &target);				// Empty Method
protected:
	DLLNode<T> *head, *tail;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr)
{
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T &el)
{
	if (tail != nullptr)
	{
		tail = new DLLNode<T>(el, nullptr, tail);
		tail->prev->next = tail;
	}
	else
	{
		head = tail = new DLLNode<T>(el, nullptr, nullptr);
	}
}

template<class T>
bool DoublyLinkedList<T>::deleteFromDLLTail(T &el)
{
	if (tail != nullptr)
	{
		el = tail->info;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		return true;
	}
	return false;
}

template<class T>
void DoublyLinkedList<T>::print()
{
	if (head == nullptr)
	{

	}
	else
	{
		DLLNode<T> *temp;
		temp = new DLLNode<T>();
		temp = head;

		while (temp != nullptr)
		{
			cout << temp->info << endl;
			temp = temp->next;
		}

	}
}

template<class T>
bool DoublyLinkedList<T>::insertBefore(T target, T &newItem)
{

	// Inform the user that the target is being searched
	cout << "Searching for " << target << endl;
	DLLNode<string> *searchNode = search(target);

	// if the list is empty we cannot insert
	if (searchNode != nullptr)
	{
		if (head == searchNode)
		{
			// We are replacing the head with the new item.
			cout << "We are replacing the head with the new item." << endl;
			// I will call the add to head method
			DLLNode<T> *newnode = new DLLNode<T>(newItem, nullptr, nullptr);
			newnode->next = head;
			head = newnode;
		}
		else
		{
			// we are inserting before an element that is not the head or tail.
			cout << "We are inserting before an element that is not the head or tail." << endl;
			DLLNode<T> *newnode = new DLLNode<T>(newItem, nullptr, nullptr);
			searchNode->prev->next = newnode;
			newnode->next = searchNode;
		}
	}
	else
	{
		cout << "Element was not found" << endl;
	}


	return false;
}

template<class T>
DLLNode<T> * DoublyLinkedList<T>::search(T &target)
{
	DLLNode<T> *temp = nullptr;

	if (head == nullptr)
	{
		return temp;
	}
	else
	{
		temp = head;
		while (temp != nullptr)
		{
			if (temp->info == target)
			{
				return temp;
			}
			else
			{
				temp = temp->next;
			}
		}
	}


	return temp;
}

template<class T>
bool DoublyLinkedList<T>::DeleteTarget(T &target)
{
	bool found = false;
}




void MainMenu()
{
	int input = 1;

	while (input != 0)
	{

		cout << "Enter an option:" << endl;
		cout << "Enter 0 to quit" << endl;
		cout << "1 to print the contents of the list" << endl;
		cout << "2 to add to the end of the list" << endl;
		cout << "3 to add to the beginning of the list" << endl;
		cout << "4 to insert an element before another" << endl;
		cout << "5 to delete an element from the tail of the list" << endl;
		cout << "6 to delete an element from the head of the list" << endl;
		cout << "7 to delete a particular element from the list" << endl;

		cout << endl;

		cin >> input;
	}
}

int main()
{
	DoublyLinkedList<string> dll;
	//MainMenu();
	dll.addToDLLTail("One");
	dll.addToDLLTail("Two");
	dll.addToDLLTail("Three");
	dll.addToDLLTail("Four");
	string element;

	cout << "Searhing for Three" << endl;

	//DLLNode<string> *searchNode = new DLLNode<string>();
	element = "Three point five";

	dll.insertBefore("Four", element);
	dll.print();
	/*while (dll.deleteFromDLLTail(element))
	{
		cout << element << endl;
	}*/

	system("pause");
    return 0;
}

