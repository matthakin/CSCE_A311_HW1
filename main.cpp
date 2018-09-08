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
	bool DeleteTarget(T &target);				// Implemented
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
			newnode->prev = searchNode->prev;
			newnode->next = searchNode;
			searchNode->prev = newnode;

		}
		return true;
	}
	else
	{
		cout << "Element was not found" << endl;
		return false;
	}



}

template<class T>
bool DoublyLinkedList<T>::DeleteTarget(T &target)
{
	cout << "Searching for " << target << endl;
	DLLNode<string> *searchNode = search(target);

	if (searchNode != nullptr)
	{
		if (searchNode == head)
		{
			// will need to replace the head

			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				DLLNode<T> *temp;
				temp = new DLLNode<T>();
				temp = head;

				head = temp->next;
				head->prev = nullptr;
				delete temp;
				cout << "Delete the head test" << endl;
				cout << head->info << endl;
			}



		}
		else if (searchNode == tail)
		{
			string dInfo = searchNode->info;
			deleteFromDLLTail(dInfo);
		}
		else
		{
			// delete something in the middle
			DLLNode<T> *temp;
			temp = new DLLNode<T>();
			temp = searchNode;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			delete searchNode;


		}


		return true;
	}
	else
	{
		return false;
	}


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



void AddtoList(DoublyLinkedList<string> *DLL2);
void DeleteTargetFromList(DoublyLinkedList<string> *DLL2);
void InsetBefore(DoublyLinkedList<string> *DLL2);
void SearchList(DoublyLinkedList<string> *DLL2);
void MainMenu(DoublyLinkedList<string> *DLL2)
{
	DoublyLinkedList<string> *theList = DLL2;
	string tailDelete = "";
	int input = 1;

	while (input != 0)
	{
		cout << endl;
		cout << "Enter an option:" << endl;
		cout << "0 to quit" << endl;
		cout << "1 to print the contents of the list" << endl;
		cout << "2 to add to the end of the list" << endl;
		cout << "3 to search the list for an Item" << endl;
		cout << "4 to insert an element before another" << endl;
		cout << "5 to delete an element from the tail of the list" << endl;
		cout << "7 to delete a particular element from the list" << endl;
		cout << endl;

		cout << endl;

		cin >> input;
		cout << endl;
		cout << endl;
		cout << endl;
		if (input > -1 && input < 8)
		{
			switch (input)
			{
			case 0:
				input = 0;
				break;
			case 1:
				theList->print();
				break;
			case 2:
				AddtoList(DLL2);
				break;
			case 3:
				SearchList(DLL2);
				break;
			case 4:
				InsetBefore(DLL2);
				break;
			case 5:
				DLL2->deleteFromDLLTail(tailDelete);
				cout << endl;
				cout << "Deleted " << tailDelete << endl;
				cout << endl;
				break;
			case 7:
				DeleteTargetFromList(DLL2);
				break;
			default:
				break;
			}
		}

	}
}

int main()
{
	DoublyLinkedList<string> *dll = new DoublyLinkedList<string>();

	dll->addToDLLTail("One");
	dll->addToDLLTail("Two");
	dll->addToDLLTail("Three");
	dll->addToDLLTail("Four");


	MainMenu(dll);
	system("pause");
    return 0;
}



void AddtoList(DoublyLinkedList<string> *DLL2)
{
	int goodInput = 0;
	DoublyLinkedList<string> *theList = DLL2;
	string input = "";
	while (goodInput == 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Enter a string to add to the list: ";
		cin >> input;
		if (input == "")
		{
			goodInput = 0;
		}
		else
		{
			goodInput = 1;
		}

	}


	DLL2->addToDLLTail(input);
	DLL2->print();

}



void DeleteTargetFromList(DoublyLinkedList<string> *DLL2)
{


	int goodInput = 0;
	DoublyLinkedList<string> *theList = DLL2;
	string input = "";

	while (goodInput == 0)
	{
		DLL2->print();
		cout << "Enter an element to delete: " << endl;

		cin >> input;

		if (input == "")
		{
			goodInput = 0;
		}
		else
		{
			DLL2->DeleteTarget(input);
			goodInput = 1;
		}


	}
}


void InsetBefore(DoublyLinkedList<string> *DLL2)
{
	int goodInput = 0;
	DoublyLinkedList<string> *theList = DLL2;
	string input = "";
	string input2 = "";

	while (goodInput == 0)
	{
		DLL2->print();
		cout << "Enter a new element: " << endl;
		cin >> input;
		cout << endl;
		cout << "You Entered " << input << endl;
		cout << endl;
		DLL2->print();
		cout << "Enter the element you want to insert the new element in front of:";
		cin >> input2;
		cout << endl;
		cout << "You entered " << input2 << endl;


		if (input == "" || input2 == "")
		{
			goodInput = 0;
		}
		else
		{
			DLL2->insertBefore(input2, input);
			DLL2->print();
			goodInput = 1;
		}


	}
}


void SearchList(DoublyLinkedList<string> *DLL2)
{
	int goodInput = 0;
	DoublyLinkedList<string> *theList = DLL2;
	DLLNode<string> *theString;
	string input = "";

	while (goodInput == 0)
	{
		DLL2->print();
		cout << "Enter an element to search " << endl;

		cin >> input;

		if (input == "")
		{
			goodInput = 0;
		}
		else
		{
			theString = DLL2->search(input);
			if (theString == nullptr)
			{
				cout << endl;
				cout << "Search found 0 results" << endl;
				cout << endl;
			}
			else
			{
				if (theString->prev == nullptr)
				{
					cout << endl;
					cout << "The item is first" << endl;
					cout << endl;
					goodInput = 1;
				}
				else if (theString->next == nullptr)
				{
					cout << endl;
					cout << "The item is Last" << endl;
					cout << endl;
					goodInput = 1;
					goodInput = 1;
				}
				else
				{
					cout << endl;
					cout << "The item was found between " << theString->prev->info << " and " << theString->next->info << endl;
					cout << endl;



					goodInput = 1;
				}
			}
		}


	}
}
