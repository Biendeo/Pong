#include <iostream>
#include "rlutil.h"
#include "Pong.h"

int main() {
	Pong g;

	rlutil::hidecursor();
	rlutil::cls();
	
	while (true) {
		g.Update();
	}

	return EXIT_SUCCESS;
}