#include "window_manager.h"
#include "debug.h"

int main(int argc, char** argv)
{
	Debug::Log("name ", "-"); Debug::Log(" cameron");
	Debug::Warning("You are running OSX");
	Debug::Error("DC failed");
	Debug::FatalError("Could not open window");

	return 0;
}