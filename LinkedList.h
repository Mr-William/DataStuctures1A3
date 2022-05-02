//*****************************************************************************************************
//
//		File:			LinkedList.h
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #3, LinkedList
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			September 14, 2020 
//
//
//		This file contains the functions that manipulate the linked list created in main driver.
//
//		Other files required: 
//			1.	LLDriver.cpp - main driver program
//          2.  Node.h - used to create nodes
//			
//*****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINDEDLIST_H
#include <new>
#include "Node.h"

using namespace std;

//*****************************************************************************************************

template <typename TYPE>
class LList
{
	private:
		Node <TYPE>* front;
	public:
		LList();
		~LList();
		bool insert(const TYPE&);
		bool remove(TYPE&);
		bool retrieve(TYPE&) const;
		bool viewFront(TYPE&) const;
		bool viewBack(TYPE&) const;
		bool isEmpty() const;
		bool isFull() const;
		bool clearList();
		bool display() const;
		int getSize() const;
};

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE> ::LList()
{
	front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE> :: ~LList()
{
	Node<TYPE>* pTemp = front;

		while ( pTemp != nullptr )
		{
			Node<TYPE>* next = pTemp->next;
			delete pTemp;
			pTemp = next;
		}
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE> :: insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pPrev = nullptr;
	Node<TYPE>* pAfter = front;

	while ( (pAfter != nullptr) && (pAfter->data < dataIn) )
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<TYPE>* pNew = new (nothrow) Node<TYPE> (dataIn, pAfter);

	if ( pNew != nullptr )
	{
		if ( pPrev != nullptr )
		{
			pPrev->next = pNew;
		}

		else
		{
			front = pNew;
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE> :: remove(TYPE& dataOut)
{
	bool success = false;

	Node<TYPE>* pTemp = front;
	Node<TYPE>* pPrev = nullptr;

	while ( (pTemp != nullptr) && (pTemp->data < dataOut) )
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if ( (pTemp != nullptr) && (pTemp->data == dataOut) )
	{
		dataOut = pTemp->data;
		
		if (pPrev != nullptr)
		{
			pPrev->next = pTemp->next;
		}

		else
		{
			front = pTemp->next;
		}

		delete pTemp;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE>:: retrieve(TYPE& data) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ( (pTemp != nullptr) && (pTemp->data < data) )
	{
		pTemp = pTemp->next;
	}

	if ( (pTemp != nullptr) && (pTemp->data == data) )
	{
		success = true;
		data = pTemp->data;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewFront(TYPE& dataOut) const
{
	bool success = false;
	
	if (front != nullptr)
	{
		dataOut = front->data;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewBack(TYPE& dataOut) const
{
	bool success = false;

	Node<TYPE>* pTemp = front;

	while ( (pTemp != nullptr) && (pTemp->next != nullptr) )
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isEmpty() const
{
	bool empty = true;

	if (front != nullptr)
		empty = false;

	return empty;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isFull() const
{
	bool full = true;
	Node<TYPE>* pTemp = new (nothrow) Node <TYPE>;

	if (pTemp != nullptr)
	{
		full = false;
		delete pTemp;
	}

	return full;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: clearList()
{
	bool hasValues = true;
	Node<TYPE>* pTemp = front;

	if ( front->next == nullptr )
		hasValues = false;

	else
	{

		while ( pTemp != nullptr )
		{
			Node<TYPE>* next = pTemp->next;
			delete pTemp;
			pTemp = next;
		}

		front = pTemp;
	}

	return hasValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: display() const
{
	bool hasValues = true;
	Node<TYPE>* pTemp = front;

	if ( pTemp == nullptr )
		hasValues = false;

	else
	{
		
		while ( (pTemp != nullptr) )
		{
			cout << pTemp->data;
			pTemp = pTemp->next;
		}
		
		cout << endl;
	}

	return hasValues;
}

//*****************************************************************************************************

template <typename TYPE>
int LList <TYPE> :: getSize() const
{
	int count = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr)
	{
		pTemp = pTemp->next;
		count++;
	}

	return count;
}

//*****************************************************************************************************

#endif