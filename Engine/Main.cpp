#include "window_manager.h"
#include "debug.h"
#include "mathf.h"
int main(int argc, char** argv)
{
	InstantiateWindow();

	Debug::Log("name ", "-"); Debug::Log(" cameron");
	Debug::Warning("You are running OSX");
	Debug::Error("DC failed");
	//Debug::FatalError("Could not open window");

	return 0;
}