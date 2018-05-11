#include "Controller.h"
#include <string.h>
using namespace std;

int Controller::transform(string disease)  //O(1)
{
	if (disease.find("gunshot") <disease.length())
		return 1;
	if (disease.find("broken") <disease.length())
		return 2;
	else return 3;
}

void Controller::addCont(string name, string disease)  //O(n) -> inherited from the PriorityQueue
{
	int p = transform(disease);
	this->q.enqueue(name, p);
}

Node* Controller::getNext() { //O(1)
	Node* n= this->q.dequeue();
	return n;
}

string Controller::treatPerson()   //O(1)
{
	Node* chosen = getNext();
	string name = chosen->info;
	delete chosen;
	return name;


}

int Controller::nrOfCases() {   //O(1)
	return this->q.length();
}

Node* Controller::getHead() {   //O(1)
	return this->q.getFirst();
}