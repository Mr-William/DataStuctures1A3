//*****************************************************************************************************
//
//		File:			LLDriver.cpp
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
//		This program is set up with pre-defined values that verify functionality of various
//      linked list manipulating functions that are outlined in header file
//
//		Other files required: 
//			1.	LinkedList.h - contains linked list functions
//          2.  Node.h - used to create nodes
//			
//*****************************************************************************************************

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

//*****************************************************************************************************

int main()
{
    LList<int> list;
    int val,
        retreiveValue = 10,                                                //defined value to retrieve
        removeValue = 1;                                                   //defined value to remove

    for ( int i = 0; i < 10; i++ )
    {
        if ( list.insert(i) )
            cout << "Inserting " << i << " into LinkedList.\n";
        else
            cout << "Error inserting " << i << endl;
    }

    if ( !list.display() )
        cout << "Error displaying values.\n";

    if (list.insert(3))
    {
        cout << "Inserting value of 3 into list:  ";
        
        if (!list.display())
            cout << "Error displaying values.\n";
    }
    else
        cout << "Couldn't insert new value.  Debug program and try again.\n";

    if ( list.remove(removeValue) )
    {
        cout << "Removing value of " << removeValue << " from the list:  ";
        
        if (!list.display())
            cout << "Error displaying values.\n";
    }
    else
        cout << "Error removing value. Debug and try again.\n";
    
    cout << "Attempting to retrieve " << retreiveValue << endl;

    if ( list.retrieve(retreiveValue) )
        cout << "Retrieved " << retreiveValue << endl;
    else
        cout << "Could not find: " << retreiveValue << endl;

    if ( list.viewFront(val) )
        cout << "Front value:  " << val << endl;
    else
        cout << "Could not retrieve front value.\n";

    if ( list.viewBack(val) )
        cout << "Back value:  " << val << endl;
    else
        cout << "Could not retrieve back value.\n";

    if ( list.isEmpty() )
        cout << "List is empty.\n";
    else
        cout << "List is not empty.\n";

    if ( !list.isFull() )
        cout << "List is not full.\n";
    else
        cout << "List is full.\n";

    val = list.getSize();

    cout << "There are " << val << " nodes.\n";

    if ( list.clearList() )
        cout << "Values cleared from list.\n";
    else
        cout << "No values to clear!\n";

    cout << "After clearing, there are " << list.getSize() << " values stored.\n";

    return 0;
}

//*****************************************************************************************************

/*

Inserting 0 into LinkedList.
Inserting 1 into LinkedList.
Inserting 2 into LinkedList.
Inserting 3 into LinkedList.
Inserting 4 into LinkedList.
Inserting 5 into LinkedList.
Inserting 6 into LinkedList.
Inserting 7 into LinkedList.
Inserting 8 into LinkedList.
Inserting 9 into LinkedList.
0123456789
Inserting value of 3 into list : 01233456789
Removing value of 1 from the list : 0233456789
Attempting to retrieve 10
Could not find: 10
Front value : 0
Back value : 9
List is not empty.
List is not full.
There are 10 nodes.
Values cleared from list.
After clearing, there are 0 values stored.

D : \OneDrive\Desktop\Webster\FA2020\Database Concepts\week 3\LLDriver\Debug\LLDriver.exe(process 11000) exited with code 0.
Press any key to close this window . . .

*/