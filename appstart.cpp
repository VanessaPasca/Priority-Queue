#include "UI.h"
#include "Controller.h"
#include <crtdbg.h>
#include "Tests.h"
bool comparingFunction(int a, int b) {
	return a <= b;
}
int main()
{
	testCont();
	{
		PriorityQueue q{ &comparingFunction };
		Controller cont{ q };
		UI ui{ cont };
		ui.run();
	}
	_CrtDumpMemoryLeaks();
}