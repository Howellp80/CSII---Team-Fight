/****************************************************************************************
** Class file: Stack.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates a simple integer Stack where a user can add and remove values
**              to and from the stack.
****************************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Creature.hpp"

class Stack
{
private:

	// the struct which will make up each node in the stack
	struct StackNode
	{
		Creature *fighterPtr;     // pointer to a Creature derived object
		StackNode *next;    // pointer to next node in the stack 
	};

	StackNode *p2Head;      // pointer to the first node in the stack

public:
	/************************************************************************************
	** Function: Stack()
	** Description: Creates a Stack object which can have integer nodes added to, or
	**              removed from it. The objects linked list is empty by default.
	************************************************************************************/
	Stack();




	/************************************************************************************
	** Function: ~Stack()  -  Destructor
	** Description: Goes through a Stacky object and deletes any remaining nodes in the
	**              linked list.
	************************************************************************************/
	~Stack();




	/************************************************************************************
	** Function: add(Creature *)
	** Description: Prompts the user to add a node to the stack.
	** Parameter: int  -  The value of the node that will be added.
	************************************************************************************/
	void add(Creature *);




	/************************************************************************************
	** Function: remove()
	** Description: Deletes a node from the stack. Nodes are deleted from the end of the
	**              linked list giving a FILO functionality.
	************************************************************************************/
	void remove();




	/************************************************************************************
	** Function: print()
	** Description: Prints the contents of the stack with older nodes at the top and
	**              newer ones at the bottom. 
	************************************************************************************/
	void print();
};

#endif