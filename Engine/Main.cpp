#include "logging.h"

int main(int argc, char** argv)
{
	GE_LOG_INFO("The logging system is up and running!");
	GE_LOG_WARNING("Quitting program");

	getchar();
	
	return 0;
}