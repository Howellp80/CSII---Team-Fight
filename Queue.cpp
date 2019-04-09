/****************************************************************************************
** Class file: Queue.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates a simple integer Queue where a user can add and remove values
**              to and from the queue.
****************************************************************************************/

#include "Queue.hpp"




/************************************************************************************
** Function: Queuey()
** Description: Creates a Queue object which can have integer nodes added to, or
**              removed from it. The objects linked list is empty by default.
************************************************************************************/
Queue::Queue()
{
	p2Head = NULL;
	p2Tail = NULL;
}




/************************************************************************************
** Function: ~Queuy()  -  Destructor
** Description: Goes through a Queue object and deletes any remaining nodes in the
**              linked list.
************************************************************************************/
Queue::~Queue()
{
	// if the user leaves with nodes still in the queue
	QueueNode *garbage = p2Head;
	QueueNode *p2node = p2Head;

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
** Description: Prompts the user to add a node to the queue.
** Parameter: int  -  The value of the node that will be added.
************************************************************************************/
void Queue::add(Creature *creat)
{
	// if the queue is empty
	if (p2Head == NULL){
		p2Head = new QueueNode;
		p2Head->fighterPtr = creat;
		p2Head->next = NULL;
		p2Head->previous = NULL;
		p2Tail = p2Head;
	}
	// if not empty, add a new node at the end
	else {
		p2Tail->next = new QueueNode;
		p2Tail->next->fighterPtr = creat;
		p2Tail->next->next = NULL;
		p2Tail->next->previous = p2Tail;
		p2Tail = p2Tail->next;
	}
}




/************************************************************************************
** Function: remove()
** Description: Deletes a node from the queue. Nodes are deleted from the front of
**              the linked list giving a FIFO functionality.
************************************************************************************/
void Queue::remove()
{
	Creature *toDel;
	QueueNode *p2node = p2Head;

	// if only 1 node in queue
	if (p2Head->next == NULL){
		toDel = p2Head->fighterPtr;
		delete p2Head;
		p2Head = NULL;
		p2Tail = NULL;
	}
	// if more than 1 node in queue
	// remove the 1st node
	else{
		QueueNode *headHolder = p2node->next;
		toDel = p2Head->fighterPtr;
		delete p2Head;
		p2Head = headHolder;
		p2Head->previous = NULL;
	}
}




/************************************************************************************
** Function: print()
** Description: goes through the list and finds the fighters with the most points
**              and prints them out if they scored more than 0 points, from 1st to
**              3rd.
************************************************************************************/
void Queue::print()
{
	std::string fCreatT = " ",
		fName = " ",
		sCreatT = " ",
		sName = " ",
		tCreatT = " ",
		tName = " ";
	int fPoints = 0,
		sPoints = 0,
		tPoints = 0;
	QueueNode *p2node = p2Head;

	// for all of the fighters in the list
	while (p2node != NULL){
		
		// get the fighters points
		int temp = p2node->fighterPtr->getPoints();

		// if the fighter has the most points
		if (temp >= fPoints){
			tCreatT = sCreatT;
			tName = sName;
			tPoints = sPoints;
			sCreatT = fCreatT;
			sName = fName;
			sPoints = fPoints;
			fCreatT = p2node->fighterPtr->getCreatType();
			fName = p2node->fighterPtr->getName();
			fPoints = temp;
		}
		// if the fighter has the second most points
		else if (temp >= sPoints){
			tCreatT = sCreatT;
			tName = sName;
			tPoints = sPoints;
			sCreatT = p2node->fighterPtr->getCreatType();
			sName = p2node->fighterPtr->getName();
			sPoints = temp;
		}
		// if the fighter has the 3rd most points
		else if (temp >= tPoints){
			tCreatT = p2node->fighterPtr->getCreatType();
			tName = p2node->fighterPtr->getName();
			tPoints = temp;
		}

		// get the next fighter
		p2node = p2node->next;
	}

	// print out the top 3 fighters that scored points
	if (fPoints > 0)
		std::cout << " 1st Placee: " << fCreatT << ", " << fName << ", with " << fPoints 
		          << " points." << std::endl;
	
	if (sPoints > 0)
		std::cout << " 2nd Placee: " << sCreatT << ", " << sName << ", with " << sPoints
		<< " points." << std::endl;

	if (tPoints > 0)
		std::cout << " 3rd Placee: " << tCreatT << ", " << tName << ", with " << tPoints
		<< " points." << std::endl;

	std::cout << std::endl;
}


// getters
Queue::QueueNode * Queue::getP2Head()
{
	return p2Head;
}
