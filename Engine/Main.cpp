<<<<<<< HEAD
#include <iostream>
#include "Mathf.h"

const int value = 129.223;
int main(int argc, char** argv) {
	std::cout << Mathf.Tan(90);
	getchar();
	return 0; 
=======
#include "window_manager.h"
#include "debug.h"

int main(int argc, char** argv)
{
	Debug::Log("name ", "-"); Debug::Log(" cameron");
	Debug::Warning("You are running OSX");
	Debug::Error("DC failed");
	Debug::FatalError("Could not open window");

	return 0;
>>>>>>> refs/remotes/origin/master
}