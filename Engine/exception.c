#include "exception.h"
#include "str.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* a good error length */
#define ERR_BUF_LEN 48

/* the default error callback implementation */
static void __defaulterrorcallback(errno_t code, const char* message, CallingContext* cc)
{
	static const char* cformatstr =  "Error: (%i) %s";
	static const char* mformatstr =  " | %s";
	static const char* ccformatstr = " | %s : %s : %i";

	char errcodemessage[ERR_BUF_LEN] = { '\0' };
	errno_t ret = error_to_str(code, &errcodemessage[0], ERR_BUF_LEN);

	if (ret != 0) 
	{ 
		fprintf(stderr, "an unknown error occurred (%i)", code); 
		goto QUITTER;
	}

	fprintf(stderr, cformatstr, code, errcodemessage);
	if (message != NULL) { fprintf(stderr, mformatstr, message); }
	if (cc != NULL) { 
		fprintf(stderr, 
		ccformatstr,
		formatFilePath(cc->file),
		cc->func, 
		cc->line); 
	}

/* close the program */
QUITTER:
	putc('\n', stderr);

	//getc(stdin);
	//exit(1); //assumes that 'exit' will safely release in use memory
}

/* defines the error callback function ptr */
static ErrorCallback currenterrcallback = __defaulterrorcallback;

/* the base call to the active error callback fnptr */
void __call_error_callback(errno_t e, const char* c, CallingContext cc) { currenterrcallback(e, c, &cc); }

/* set the error callback function pointer to call whenever an error occurs */
void set_error_callback(ErrorCallback fnptr) { currenterrcallback = fnptr; }

/* reverts the internal error callback to default */
void reset_error_callback(void) { currenterrcallback = __defaulterrorcallback; }

/* just a strerror wrapper */
errno_t error_to_str(errno_t code, char* buf, int bufsize)
{
	errno_t successs;
	if (code <= 0 || code > ERR_SYM_COUNT) { successs = strncpy_s(buf, bufsize, "Unknown error", bufsize-1); }
	else								 { successs = strerror_s(buf, bufsize, code); }

	return successs;
}

/* this logic is run, on an assertion failure */
void __assertion_failure(CallingContext cc, const char* expr)
{
	fputs("Debug assertion failed!\n\n", stderr);
	fprintf(stderr, "File: %s\n", cc.file);
	fprintf(stderr, "Func: %s\n", cc.func);
	fprintf(stderr, "Line: %i\n", cc.line);

	//getc(stdin);
	//exit(1);
}

/* allows the file stream being written to, to be changed */
/* void seterrorstream(FILE* stream) { activestream = stream; } */

/* returns the current file stream being written to */
/* FILE* geterrorstream(void) { return activestream; } */