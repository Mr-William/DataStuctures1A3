//*****************************************************************************************************
//
//		File:			Node.h
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
//		This file contains the definition for node creation.
//
//		Other files required: 
//			1.	LinkedList.h - contains linked list functions
//          2.  LLDriver.cpp - main driver program
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>

struct Node
{
	TYPE data;
	Node <TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node(TYPE d, Node <TYPE>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif