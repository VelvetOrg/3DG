#include "pngreader.h"

int read(const char* filepath, PNG &png) {
	
	FILE* file = nullptr; //Filestream
	//Stores the error code
	errno_t	error = fopen_s(&file, "C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\PNG-gradient.png", "rb");
	if (error != 0x0) {
		//Close file on failure
		fputs("File could not be opened.\n", stderr);
		return -1; // error: file could not be opened
	}
	else {
		fputs("File opened.\n", stdout);
	}

	GE_BYTE temp_header[8] = {};
	fread(temp_header, 1, 8, file);

	if (memcmp(signature, temp_header, sizeof(temp_header)) == 0x0) {
		fputs("\nHeader is correct.\n", stdout);
	}
	else {
		fputs("\nHeader does not match.\n", stderr);
		return -2; // error: header does not match
	}

	//Return memory
	free(temp_header);

	//Read IHDR length
	fread(png.IHDR.length, 1, 4, file);
	fprintf(stdout, "\nChunk Length (in bytes): %d\n", read32bitInt(png.IHDR.length));
	
	//Read IHDR type
	fread(png.IHDR.chunkType, 1, 4, file);
	fputs("Chunk Type: ", stdout);
	for (int i = 0; i < 4; i++) {
		printf("%c", (char)png.IHDR.chunkType[i]);
	}
	fputs("\n", stdout);

	fread

	png.IHDR.data.push_back(     read(        ))

	return 0; // success!
}