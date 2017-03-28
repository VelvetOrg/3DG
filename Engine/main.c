#include "exception.h" 

#include <stdio.h>
#include <errno.h>

main()
{
	//SASSRT(42 == 0, "oh no"); 
	ASSRT(42 == 0);
	ERROR(EIO);
	ERROR_C(E2BIG);
	ERROR_RS("Test message");
	ERROR_S(EACCES, "Test message");

	getchar();

	//QUIT();

	return 0;
}