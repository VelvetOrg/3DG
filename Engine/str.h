#ifndef _STR_H
#define _STR_H

#ifdef __cplusplus
extern "C" {
#endif

/* makes a file format string relative to the current directory */
const char* formatFilePath(const char* p);

/* quick int (single digit) to char */
/* inline */ char Qitoc(unsigned short i);

/* safe int (single digit) to char */
/* inline */ char Sitoc(unsigned short i);

/* quick char to int */
/* inline */ unsigned short Qctoi(char c);

/* safe char to int */
/* inline */ unsigned short Sctoi(char c);

void Quitostr(const char* buffer, unsigned short len, unsigned int u);
void itostr	(const char* buffer, unsigned short len, int i);
void ftostr	(const char* buffer, unsigned short len, float f);
void dtostr	(const char* buffer, unsigned short len, double d);

#ifdef __cplusplus
}
#endif

#endif