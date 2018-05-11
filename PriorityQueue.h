#pragma once
#include <vector>
//this is a medical case
class Node {
public:
	int priority;
	std::string info;
	Node* next;
};

class PriorityQueue {
private:
	Node * head;
	bool (*relation)(int a,int b);
public:
	PriorityQueue(bool (*r)(int a,int b)) :relation{ r } {};
	/*
	Constructor 
	In: pointer to function which will determine the order in the queue

	*/
	~PriorityQueue();
	/*
	Destructor
	*/
	void enqueue(std::string item, int priority);
	/*
	Enqueues the item with the given priority in the queue.

	*/
	Node* dequeue();
	/*
	Dequeues one element from the queue and returns it.

	*/
	int length();
	/*
	Returns the nr of elements in the queue
	*/
	Node* getFirst();
	/*
	returns the first element, the head of the queue
	*/

};
