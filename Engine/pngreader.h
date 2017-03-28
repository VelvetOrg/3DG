// Multiplatform meme
#ifndef _PNGREADER_H_
#define _PNGREADER_H_

//Our typedefs
#include "types.h"

//Pixel data meme
#include <vector>

//For endian meme
//#include <WinSock2.h>

//Store colours
#include "colour.h"

//Proper PNG signature
static const GE_BYTE signature[8] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A }; //Used for comparison

//Proper PLTE signature
static const GE_BYTE plte_signature[8] = { 0x50, 0x4C, 0x54, 0x3B }; //Used for comparison

//Various colour types
/*
*	Bit depth for each colour type are found in the ancillary sBIT chunk
*/
#define PNG_COLOUR_TYPE_BW			0 
#define PNG_COLOUR_TYPE_RGB			2
#define PNG_COLOUR_TYPE_PLTE_INDEX	3
#define PNG_COLOUR_TYPE_BWA			4 
#define PNG_COLOUR_TYPE_RGBA		5

//Various filter/recon types
/*
	Recon is positive version of filters
*/
#define PNG_FILTER_TYPE_NONE		0
#define PNG_FILTER_TYPE_SUB			1
#define PNG_FILTER_TYPE_UP			2
#define PNG_FILTER_TYPE_AVG			3
#define PNG_FILTER_TYPE_PAETH		4

/*
PNG Chunks are formatted like this:
- 4 bytes for their length
- 4 bytes for the "type of chunk", whatever that means lol
- n bytes for the chunk's data
- 4 bytes for the cyclic redundancy check, computed at the end of reading
*/
typedef struct pngchunk {
	GE_UINT length;
	GE_UCHAR type[4];
	std::vector<GE_BYTE> data;
	GE_UINT cyclicRedundancyCheck;
};

typedef struct IHDR {
	GE_UINT length;
	GE_UCHAR type[4] = {};
	GE_UINT width;
	GE_UINT height;
	GE_BYTE bitDepth;
	GE_BYTE colourType;
	GE_BYTE compressionMethod;
	GE_BYTE filterMethod;
	GE_BYTE interlaceMethod;
};

typedef struct PLTE {
	GE_UINT length;
	GE_UCHAR type[4] = {};
	Colour* colours;
};

typedef struct PNG {
	IHDR IHDR;
	PLTE PLTE;
	std::vector<pngchunk> IDATs;
	pngchunk IEND;
	//Vector for colour data
};

typedef struct compressedDataStream {
	GE_BYTE zlibCompFlag;
	GE_BYTE checkBit;
	GE_BYTE* data;
	GE_UINT crc;
};

//Pack a 4 byte array directly into a 32 bit INT 
inline GE_INT32 read32bitInt(GE_BYTE* value) {
	return (value[0] << 24) | (value[1] << 16) | (value[2] << 8) | (value[3]);
}

//Fun func decleartion
int read(const char* filepath, PNG &png);

#endif