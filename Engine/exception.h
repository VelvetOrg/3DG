//TODO: program console
//TODO: colour console
//TODO: more versatile error callback
#ifndef _EXCEPTION_H
#define _EXCEPTION_H

//TODO: avoid including this:
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* adds an unknown error to the POSIX codes */
#define EUNKNOWN 0

/* defines the number of error codes, Linux specific */
#define ERRSYMCOUNT 140

//bad code
typedef int errno_t;

/* holds information about the macro caller */
typedef struct
{
	int line;
	const char* file;
	const char* func;

} calling_context;

/* defines an error callback function, this is called when ever an error occurs */
/* errno_t is the POSIX error code */
/* const char*[1] is detailed error info, or NULL */
/* calling_context is info about the caller or NULL */
typedef void(*error_callback)(errno_t, const char*, calling_context*);
typedef void(*info_callback)(const char*, calling_context*);

/* set the error callback function pointer to call whenever an error occurs */
INLINE void seterrorcallback(error_callback fnptr);

/* reverts the internal error callback to default */
INLINE void reseterrorcallback(void);

/* like strerror, converts error code into info string */
/* recommended buffer size is 48 */
errno_t errtostr(errno_t code, char* buf, int bufsize);

/* error code */
INLINE void errorc(errno_t code);

/* error raw string */
INLINE void errorrs(const char* message);

/* error string */
INLINE void errors(errno_t code, const char* message);

/* detailed error, caller */
INLINE void errord(errno_t code, calling_context ctx, const char* message);

/* this logic is run, on an assertion failure */
void __assertion_failure(calling_context cc, const char* expr);

/* formatted error */
//TODO: formatted errors
//INLINE void errorf(errno_t code, const char* format, ...);
//INLINE void errorfd(errno_t code, calling_context ctx, const char* format, ...);

/* allows for a calling context to be generated from the current line */
#define currentcallingcontext (calling_context) { __LINE__, __FILE__, __func__ }

/* allows the file stream being written to, to be changed */
/* for example stderr is used by default, but a a log file may be wanted */
/* INLINE void seterrorstream(FILE* stream); */

/* returns the current file stream being written to */
/* INLINE FILE* geterrorstream( void ); */

/* literally just like assert.h, but without an additional include */
#ifdef NDEBUG
#define asrt(expression) (void(0))
#else
#define asrt(expression) ( (expression)?((void)0) : __assertion_failure(currentcallingcontext, #expression) )
#endif

#define sasrt(expression) static_assert(expression)

/* allow for detailed error messages without a whole lot of typing */
#define err(code)			errord(code, currentcallingcontext, NULL);
#define errs(code, message)	errord(code, currentcallingcontext, message);
//#define errf(n, m, ...)

/* quits the program, should only be used in an emergency */
#define quit() exit(1)
#define fquit() abort()

#ifdef __cplusplus
}
#endif

#endif // !_EXCEPTION_H