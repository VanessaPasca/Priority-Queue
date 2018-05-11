#include "UI.h"
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

void UI::printMenu()
{
	cout << "----------------------------------------------------" << endl;
	cout << "Options are: \n" << endl;
	cout << "1.Add new medical case" << endl;
	cout << "2.Treat a person" << endl;
	cout << "3.See all current cases" << endl;
	cout << "0.Exit" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
}

void UI::run() {
	while (1) {
		printMenu();
		int cmd{ -1 };
		do{
			cout << "Give your command: "<<endl;
			cin >> cmd;
			cout << endl;
			}
		while (cmd < 0 || cmd>4);
			switch (cmd) {
			case 0: {
				return;
			}
			case 1: {
				string name,issue;
				cin.ignore();
				cout << "Give the name of the patient:";
				getline(cin, name);
				cout << "Give medical issue:";
				getline(cin, issue);
				this->cont.addCont(name, issue);
				displayAll();
				break;

			}
			case 3: {
				displayAll();
				break;
			}
			case 2: {
				this->cont.treatPerson();
				displayAll();
				
				break;
			}
					
		}

	}
}


void UI::displayAll() {
	Node* n = this->cont.getHead();
	if (n == NULL)
		cout << "No cases!" << endl;
	while (n != NULL) {
		cout << "Pacient name: " << n->info << " which has priority " << n->priority << endl;
		n = n->next;
	}
}