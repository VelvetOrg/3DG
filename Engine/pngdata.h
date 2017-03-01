#ifndef _pngdata_h
#define _pngdata_h

#include "types.h"

class PNGData {
public:
	GE_UCHAR header[8]; // PNG Header is 8 bytes
	GE_UINT width; // Image's width
	GE_UINT height; // Image's height
	GE_UINT size; // Image's total size = width * height

};

#endif