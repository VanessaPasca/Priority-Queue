#pragma once
#include "Controller.h"
class UI {
private:
	Controller cont;
public:
	UI(Controller c) :cont{ c } {};
	void printMenu();
	void run();
	void displayAll();

};