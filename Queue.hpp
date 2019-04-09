/****************************************************************************************
** Class file: Queue.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates a simple integer Queue where a user can add and remove values
**              to and from the queue.
****************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "Creature.hpp"

class Queue
{
private:

	// the struct which will make up each node in the queue
	struct QueueNode
	{
		Creature *fighterPtr;  // pointer to a Creature derived object
		QueueNode *next;        // pointer to next node in the queue
		QueueNode *previous;    // pointer to previous node in the queue
	};

	QueueNode *p2Head;      // pointer to the first node in the queue
	QueueNode *p2Tail;      // pointer to the last node in the queue


public:

	/************************************************************************************
	** Function: Queue()
	** Description: Creates a Queue object which can have integer nodes added to, or
	**              removed from it. The objects linked list is empty by default.
	************************************************************************************/
	Queue();




	/************************************************************************************
	** Function: ~Queue()  -  Destructor
	** Description: Goes through a Queue object and deletes any remaining nodes in the
	**              linked list.
	************************************************************************************/
	~Queue();




	/************************************************************************************
	** Function: add(int)
	** Description: Prompts the user to add a node to the queue.
	** Parameter: int  -  The value of the node that will be added.
	************************************************************************************/
	void add(Creature *);




	/************************************************************************************
	** Function: remove()
	** Description: Deletes a node from the queue. Nodes are deleted from the front of
	**              the linked list giving a FIFO functionality.
	************************************************************************************/
	void remove();




	/************************************************************************************
	** Function: print()
	** Description: goes through the list and finds the fighters with the most points
	**              and prints them out if they scored more than 0 points, from 1st to
	**              3rd.
	************************************************************************************/
	void print();


	// getters
	Queue::QueueNode * getP2Head();
};

#endif