#include "str.h"
#include "platform.h"

#include <string.h>

#ifdef GE_OS_WINDOWS
const char* formatFilePath(const char* p) { return strrchr(p, '\\') ? strrchr(p, '\\') + 1 : p; }
#else
const char* formatFilePath(const char* p) { return strrchr(p, '/') ? strrchr(p, '/') + 1 : p; }
#endif // GE_OS_WINDOWS

//int and char conversion
char Sitoc(unsigned short i){ return (i < 10) ? i + 0x30 : '0';}
char Qitoc(unsigned short i){ return i + 0x30; }
unsigned short Qctoi(char c) { return c - 0x30; }
unsigned short Sctoi(char c) { return (c >= 0x30 && c <= 0x39) ? c - 0x30 : 0; }

/* puts an unsigned int into string form */
void Quitostr(const char* buffer, unsigned short len, unsigned int u)
{

}