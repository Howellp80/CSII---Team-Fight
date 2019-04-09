/****************************************************************************************
** Class file: Stack.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates a simple integer Stack where a user can add and remove values
**              to and from the stack.
****************************************************************************************/

#include "Stack.hpp"




/************************************************************************************
** Function: Stack()
** Description: Creates a Stack object which can have integer nodes added to, or
**              removed from it. The objects linked list is empty by default.
************************************************************************************/
Stack::Stack()
{
	p2Head = NULL;
}




/************************************************************************************
** Function: ~Stack()  -  Destructor
** Description: Goes through a Stack object and deletes any remaining nodes in the
**              linked list.
************************************************************************************/
Stack::~Stack()
{
	// if the user leaves with nodes still in the stack
	StackNode *garbage = p2Head;
	StackNode *p2node = p2Head;

	// if the stack isn't empty
	if (p2Head != NULL){
		// if there is only 1 node
		if (p2node->next == NULL){
			delete p2node;
			p2Head = NULL;
		}
		// there are more than 1 nodes
		else {
			while (p2node){
				garbage = p2node;
				p2node = p2node->next;
				delete garbage;
			}
		}
	}
}





/************************************************************************************
** Function: add(int)
** Description: Prompts the user to add a node to the stack.
** Parameter: int  -  The value of the node that will be added.
************************************************************************************/
void Stack::add(Creature *creat)
{
	// if the stack is empty
	if (p2Head == NULL){
		p2Head = new StackNode;
		p2Head->fighterPtr = creat;
		p2Head->next = NULL;
	}
	// if not, add the new node at the end of the list
	else {
		StackNode *p2node = p2Head;
		while (p2node->next != NULL)
			p2node = p2node->next;
		// hey, it works :P
		p2node->next = new StackNode;
		p2node->next->fighterPtr = creat;
		p2node->next->next = NULL;

	}
}




/************************************************************************************
** Function: remove()
** Description: Deletes a node from the stack. Nodes are deleted from the end of the
**              linked list giving a FILO functionality.
************************************************************************************/
void Stack::remove()
{
	Creature *toDel;                             // value being deleted 
	StackNode *previousNode = p2Head;
	StackNode *p2node = p2Head;

	// if theres only one node in the stack
	if (p2Head->next == NULL){
		toDel = p2Head->fighterPtr;
		delete p2Head;
		p2Head = NULL;
	}
	// find the last node and delete that one
	else{
		// at the last node?
		while (p2node->next != NULL){
			previousNode = p2node;
			p2node = p2node->next;
		}

		// capture deleted value and delete the node
		toDel = p2node->fighterPtr;
		delete p2node;

		// set the newly last node's next ptr to NULL
		previousNode->next = NULL;
	}
}




/************************************************************************************
** Function: print()
** Description: 
************************************************************************************/
void Stack::print()
{
	std::cout << std::endl << " -xxx- Defeated Fighters -xxx-" << std::endl << std::endl;
	std::cout << " In the order they were K.O'd:" << std::endl;
	StackNode *p2node = p2Head;
	while (p2node != NULL){
		std::cout << "  " << p2node->fighterPtr->getCreatType() << ", " 
			      << p2node->fighterPtr->getName() << std::endl;

		p2node = p2node->next;
	}
	std::cout << std::endl;
}

