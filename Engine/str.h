#ifndef _STR_H
#define _STR_H

#include "definitions.h"

/* makes a file format string relative to the current directory */
extern const char* remove_file_path(const char* p);

/* quick int (single digit) to char */
extern INLINE char itoc_s(unsigned short i);

/* safe int (single digit) to char */
extern INLINE char itoc_q(unsigned short i);

/* quick char to int */
extern INLINE unsigned short ctoi_q(char c);

/* safe char to int */
extern INLINE unsigned short ctoi_s(char c);

#if TO_DO
extern void uitostr_q(const char* buffer, unsigned short len, unsigned int u);
extern void itostr	(const char* buffer, unsigned short len, int i);
extern void ftostr	(const char* buffer, unsigned short len, float f);
extern void dtostr	(const char* buffer, unsigned short len, double d);
#endif /* TO_DO */

#endif