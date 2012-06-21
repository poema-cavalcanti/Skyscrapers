/**********************************************************
  Title: LList.h
  Abstract: Template file for a linked list.
			Functions
			LList()
			~LList()
			LList(const LList & original)
			void insert(ElementType item, int pos)
			void orderInsert(ElementType item)
			void erase(int index)
			void display(ostream & out) const
			int getSize() const
			int search()
  Author: Poema Cavalcanti
**********************************************************/

#include <iostream>
using namespace std;

#ifndef LLIST
#define LLIST

template <typename ElementType>
class LList
{
private:
    class Node
    {
    public:
        ElementType data;
        Node * next;
        Node(){next = NULL;}
		Node(ElementType dataValue) 
        {data = dataValue; next = NULL;}
    };

    Node *first;
    int mySize;

public:
	/***********************
	  DEFAULT CONSTRUCTOR
	***********************/
    LList();

	/*************
	  DESTRUCTOR
	*************/
    ~LList();

	/*******************
	  COPY CONSTRUCTOR
	*******************/
    LList(const LList & original);

	/***********************************************************
	  INSERT

	  Function takes in two parameters. The first parameter is
	  the item to be inserted in the list and the second para-
	  meter is the index at which the item is to be inserted.
	************************************************************/
    void insert(ElementType item, int pos);

	void orderInsert(ElementType item);

	/**************************************************************
	  ERASE

	  Function takes in one parameter. The parameter is the index
	  of the item to be removed from the list.
	**************************************************************/
    void erase(int index);

	/*******************************************
	  DISPLAY
	  Displays all items in the list in order.
	********************************************/
	void display(ostream & out) const;

	/******************
	  GET SIZE
	  Returns mySize.
	******************/
	int getSize() const;

	ElementType get_element_data(int pos) ;
};

// DEFAULT CONSTRUCTOR
template <typename ElementType>
LList<ElementType>::LList()
{
    mySize = 0;
    first = NULL;
}

// DESTRUCTOR
template <typename ElementType>
LList<ElementType>::~LList()
{
	//cout << "\nDestructor Called\n";
    Node * prev = first;
    Node * ptr;
       
    while (prev != NULL)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
       
}

// COPY CONSTRUCTOR
template <typename ElementType>
LList<ElementType>::LList(const LList & original)
{
	cout << "\nCopy Constructor Called\n";
	mySize = original.mySize;
	first = NULL;
	
	if (mySize == 0) 
		return;

	Node * origPtr, * lastPtr;
	first = new Node(original.first->data); // copy first node
	lastPtr = first;
	origPtr = original.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}

// INSERT
template <typename ElementType>
void LList<ElementType>::insert(ElementType item, int pos)
{
    if (pos < 0 || pos > mySize)

    {
        cerr << "Illegal location to insert -- " << pos << endl;
        return;
    }
       
    Node * newPtr = new Node(item);
    Node * predPtr = first;
    if (pos == 0)
    {
        newPtr->next = first;
        first = newPtr;
    }
    else
    {
        for(int i = 1; i < pos; i++)
        {
            predPtr = predPtr->next;
        }
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    }
    mySize++;   
}

// ERASE
template <typename ElementType>
void LList<ElementType>::erase(int index)
{
    if (index < 0 || index >= mySize)
    {
        cerr << "Illegal location to delete -- " << index << endl;
        return;
    }
   
    Node * ptr;
    Node * predPtr = first;
    if (index == 0)
    {
        ptr = first;
        first = ptr->next;
        delete ptr;
    }
    else
    {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
    }
        mySize--;
   
}

// DISPLAY
template <typename ElementType>
void LList<ElementType>::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

template <typename ElementType>
ElementType LList<ElementType>::get_element_data(int pos) 
{
	Node * ptr = first;
	for (int i = 0; i < pos; i++)
	{
		if (ptr == NULL) {
			cout << "ERROR 401" << endl;
		}
		ptr = ptr->next;
	}

	return ptr->data;
}

//  ORDER INSERT
template <typename ElementType>
void LList<ElementType>::orderInsert(ElementType item)
{
	Node *newPtr = new Node(item);

	if(mySize == 0)
	{
		first = newPtr;
		newPtr->next = NULL;
		mySize++;
		return;
	}
	
	if(newPtr->data < first->data){
		newPtr->next = first;
		first = newPtr;
		mySize++;
		return;
	}

	Node * prevPtr = first;
	int i = 0;

	for(int i = 0; i < mySize; i++)
    {
		if(prevPtr->next == NULL)
			break;
        if(newPtr->data <= (prevPtr->next)->data){
			newPtr->next = prevPtr->next;
			prevPtr->next = newPtr;
			mySize++;
			return;
		}
		prevPtr = prevPtr->next;		
    }
   
	newPtr->next = NULL;
	prevPtr->next = newPtr;
    
    mySize++;
	return;
}

// GET SIZE
template <typename ElementType>
int LList<ElementType>::getSize() const
{
	return mySize;
}

#endif