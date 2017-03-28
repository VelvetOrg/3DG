#include "exception.h" 
#include <assert.h>
#include <errno.h>

main()
{
	asrt(1 == 2);
	errs(ENOMEM, "Leaking program");

	return 0;
}