#include "Bullet_HellApp.h"

int main() {
	
	// allocation
	auto app = new Bullet_HellApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}