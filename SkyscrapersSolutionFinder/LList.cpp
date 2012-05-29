#include "LList.h"


LList::LList()
{
    mySize = 0;
    first = NULL;
}

LList::~LList()
{
	cout << "\nDestructor Called\n";
    Node * prev = first;
    Node * ptr;
       
    while (prev != NULL)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
       
}

LList::LList(const LList & original)
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

void LList::insert(ElementType item, int pos)
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

void LList::erase(int index)
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

// This function shows the general algorithm for traversing a linked list
// See the implementation of display below to see how you might use this
// to do something useful like print out the elements in a list
void LList::traverse()
{
	Node * ptr = first;
	while(ptr != 0)
	{
		ptr = ptr->next;
	}
}

//-- Definition of display()
void LList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

//  Implement me for lab #8!
void LList::orderInsert(ElementType item)
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
