#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void PriorityQueue::enqueue(std::string item, int priority) {
	//BC: O(1)  -> when is empty or needs to be inserted 
	//AC: O(n)   -> computed using the probability formula
	// Sum( P(I)*E(I))   , P(I) =1/n+1
	// E(I) , nr of operations for each input , is i 
	// WC: O(n) (Theta)
	// Overall: O(n)
	Node *newNode;
	newNode = new Node;
	newNode->info = item;
	newNode->priority = priority;
	if (this->head == NULL)
		this->head = newNode;
	else
		if ((*relation)(this->head->priority, priority) == false)
		{
			newNode->next = this->head;
			this->head = newNode;
		}
		else {
			Node* cNode = this->head;
			while (cNode->next != NULL && (*relation)((cNode->next)->priority, priority) == true)
				cNode = cNode->next;
			newNode->next = cNode->next;
			cNode->next = newNode;
		}
}

Node* PriorityQueue::dequeue() //O(1)
{
	if (this->head == NULL) return NULL;
	Node* dq = this->head;
	this->head = this->head->next;
	return dq;
}

int PriorityQueue::length() { //O(n)
	if (this->head == NULL) return 0;
	int k = 1;
	Node* cNode = this->head;
	while (cNode->next != NULL) {
		k++;
		cNode = cNode->next;
	}
	return k;
}

PriorityQueue::~PriorityQueue() {//O(n)
	Node* cNode = this->head;
	while (cNode != NULL) {
		this->head = this->head->next;
		delete cNode;
		cNode = this->head;
	}
}
	
Node* PriorityQueue::getFirst() {   //O(1)
	return this->head;

}

	
	


