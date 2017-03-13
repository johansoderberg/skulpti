#include "stdafx.h"
#include <iostream>
#include "PAPWindow.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Starting skulpti.\n";

	PAPWindow* win = NULL;
	try {
		win = new PAPWindow("skulpti");
	}
	catch (...) {
		cout << "Exception in window creation.\n";		
	}
	win->start();

	if (win != NULL) {
		delete win;
	}

    return 0;
}



