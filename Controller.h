#pragma once
#include "PriorityQueue.h"
#include <vector>
class Controller {
private:
	PriorityQueue q;
public:
	Controller(PriorityQueue qu) :q{ qu } {};
	//Constructor
	Node* getNext();
	//the function which plays the role of the nurse, the one that chooses which patient will be treated next
	void addCont(std::string name,std::string disease);
	// adds a new medical condition to the priority queue
	std::string treatPerson();
	//the function which plays the role of the doctor
	int transform(std::string disease);
	/*
	In: a string naming a disease
	Out: the priority number established by the statement
	*/
	int nrOfCases();
	/*
	Returns the nr of current cases
	*/
	Node* getHead();
	/*
	Returns the first element in the queue, the head
	*/
};
