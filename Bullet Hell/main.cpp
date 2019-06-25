#include "Game.h"
#include "Defines.h"

int main() {
	
	// allocation
	auto app = new Game();

	// initialise and loop
	app->run("aestivation", SCR_WIDTH, SCR_HEIGHT, false);

	// deallocation
	delete app;

	return 0;
}