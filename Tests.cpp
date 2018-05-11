#include "Tests.h"
#include <assert.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool rr(int a, int b) {
	return a <= b;
}

void testCont() {
	{PriorityQueue q{ &rr };
	Controller cont{ q };
	assert(cont.nrOfCases() == 0);
	cont.addCont("Jason", "gunshot-wound");
	cont.addCont("Annie", "paper cut");
	cont.addCont("Manuel", "broken leg");
	assert(cont.getHead()->info == "Jason");
	cont.addCont("Carla", "broken rib");
	cont.addCont("Clark", "nausea");
	assert(cont.nrOfCases() == 5);
	cont.treatPerson();
	assert(cont.nrOfCases() == 4);
	assert(cont.getHead()->info == "Manuel");
	cont.addCont("James", "gunshot-wound");
	assert(cont.getHead()->info == "James");
	cont.addCont("Priscilla", "gunshot-wound");
	cont.addCont("George", "broken neck");
	cont.addCont("Julia", "paper cut");
	assert(cont.nrOfCases() == 8);
	cont.addCont("Tarek", "gunshot-wound");
	cont.addCont("Amir", "paper cut");
	assert(cont.nrOfCases() == 10);
	assert(cont.getHead()->info != "Priscilla");

	cont.treatPerson();
	assert(cont.getHead()->info == "Priscilla");
	cont.treatPerson();
	assert(cont.getHead()->info == "Tarek");
	cont.treatPerson();
	assert(cont.getHead()->info == "Manuel");
	cont.treatPerson();
	assert(cont.getHead()->info == "Carla");

	cont.treatPerson();
	assert(cont.getHead()->info == "George");

	cont.treatPerson();
	assert(cont.getHead()->info == "Annie");

	cont.addCont("Michelle", "gunshot wound");

	assert(cont.getHead()->info == "Michelle");

	cont.treatPerson();
	assert(cont.getHead()->info == "Annie");


	cont.treatPerson();
	assert(cont.getHead()->info == "Clark");

	cont.treatPerson();
	assert(cont.getHead()->info == "Julia");

	assert(cont.nrOfCases() == 2);

	cont.treatPerson();
	assert(cont.getHead()->info == "Amir");

	cont.treatPerson();
	assert(cont.getHead()==NULL);

	assert(cont.nrOfCases() == 0);



	


	}
}