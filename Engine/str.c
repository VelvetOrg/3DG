#include "str.h"
#include "platform.h"

#include <string.h>

#ifdef GE_OS_WINDOWS
const char* remove_file_path(const char* p) { return strrchr(p, '\\') ? strrchr(p, '\\') + 1 : p; }
#else
const char* remove_file_path(const char* p) { return strrchr(p, '/') ? strrchr(p, '/') + 1 : p; }
#endif // GE_OS_WINDOWS

//int and char conversion
char itoc_s(unsigned short i){ return (i < 10) ? i + 0x30 : '0';}
char itoc_q(unsigned short i){ return i + 0x30; }
unsigned short ctoi_q(char c) { return c - 0x30; }
unsigned short ctoi_s(char c) { return (c >= 0x30 && c <= 0x39) ? c - 0x30 : 0; }

/* puts an unsigned int into string form */
void uitostr_q(const char* buffer, unsigned short len, unsigned int u)
{
	//something..
}