// @todo: program console
// @todo: colour console
// @todo: more versatile error callback
#ifndef _EXCEPTION_H
#define _EXCEPTION_H

// @todo: avoid including this:
#include "definitions.h"

/* adds an unknown error to the POSIX codes */
#define EUNKNOWN 0

/* defines the number of error codes, Linux specific */
#define ERR_SYM_COUNT 140

/* forward declare */
typedef int errno_t;

/* holds information about the macro caller */
typedef struct
{
	int line;
	const char* file;
	const char* func;

} CallingContext;

/* allows for a calling context to be generated from the current line */
#define __CURRENT_CALLING_CONTEXT (CallingContext) { __LINE__, __FILE__, __func__ }

/* defines an error callback function, this is called when ever an error occurs */
/* errno_t is the POSIX error code */
/* const char* is detailed error info, or NULL */
/* CallingContext is info about the caller or NULL */
typedef void(*ErrorCallback)(errno_t, const char*, CallingContext*); 

/* set the error callback function pointer to call whenever an error occurs */
extern INLINE void set_error_callback(ErrorCallback fnptr);

/* reverts the internal error callback to default */
extern INLINE void reset_error_callback(void);

/* like strerror, converts error code into info string */
/* recommended buffer size is 48 */
extern errno_t error_to_str(errno_t code, char* buf, int bufsize);

/* the base call to the active error callback fnptr */
extern INLINE void __call_error_callback(errno_t e, const char* c, CallingContext cc);

/* this logic is run, on an assertion failure */
extern void __assertion_failure(CallingContext cc, const char* expr);

/* literally just like assert.h, but without an additional include */
#ifdef NDEBUG
#define ASSRT(expression) (void(0))
#else
#define ASSRT(expression) ( (expression)?((void)0) : __assertion_failure(__CURRENT_CALLING_CONTEXT, #expression) )
#endif

#define SASSRT(condition, err) static_assert(condition, err)

/* wrapper calls */
#define ERROR(code)				__call_error_callback(code, NULL, __CURRENT_CALLING_CONTEXT);
#define ERROR_S(code, message)	__call_error_callback(code, message, __CURRENT_CALLING_CONTEXT);
#define ERROR_RS(message)		__call_error_callback(EUNKNOWN, message, __CURRENT_CALLING_CONTEXT);
#define ERROR_C(n) ERROR(n)

#if TO_DO
/* formatted error */
INLINE void errorf(errno_t code, const char* format, ...);
INLINE void errorfd(errno_t code, calling_context ctx, const char* format, ...);

/* allows the file stream being written to, to be changed */
/* for example stderr is used by default, but a a log file may be wanted */
INLINE void seterrorstream(FILE* stream);

/* returns the current file stream being written to */
INLINE FILE* geterrorstream( void );

#define ERROR_F(n, m, ...)

//...
#endif

#endif // !_EXCEPTION_H