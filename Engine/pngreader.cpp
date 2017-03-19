#include "pngreader.h"
#include <iostream>

int read(const char* filepath, PNG &png) {
	
#pragma region CreateFilestream
	FILE* file = nullptr; //Filestream
	//Stores the error code
	errno_t	error = fopen_s(&file, filepath, "rb");
#pragma endregion

#pragma region Read_IHDR
	//Check for errors with opening filestream
	if (error != 0x0) {
		//Close file on failure
		fputs("File could not be opened.\n", stderr);
		return -1; // error: file could not be opened
	}
	else {
		fputs("File opened.\n", stdout);
	}
	
	//New scope
	{
		GE_BYTE temp_header[8] = {};
		fread(temp_header, 1, 8, file);

		if (memcmp(signature, temp_header, sizeof(temp_header)) == 0x0) {
			fputs("\nHeader is correct.\n", stdout);
		}
		else {
			fputs("\nHeader does not match.\n", stderr);
			return -2; // error: header does not match
		}
	}

	//New scope
	{
		//Read IHDR length
		GE_BYTE temp_chunk_total_length[4] = {};
		//Read into buffer
		fread(temp_chunk_total_length, sizeof(GE_BYTE), 4, file); //Moves file pointer by 4
		png.IHDR.length = read32bitInt(temp_chunk_total_length);
		//Slow printing
		fprintf(stdout, "\nChunk Length: %i\n", png.IHDR.length);
	}

	//New scope
	{
		//Read IHDR chunk type
		fread(png.IHDR.type, sizeof(GE_UCHAR), 4, file);
		//Slow printing
		fputs("Chunk Type: ", stdout);
		for (int i = 0; i < 4; i++) {
			printf("%c", (char)png.IHDR.type[i]);
		}
		fputs("\n", stdout);
	}

	//New scope
	{
		//Read image width
		GE_BYTE temp_width[4] = {};
		fread(temp_width, sizeof(GE_BYTE), 4, file);
		png.IHDR.width = read32bitInt(temp_width);
		//Slow printing
		fprintf(stdout, "Image Width: %d\n", png.IHDR.width);

		//Read image height
		GE_BYTE temp_height[4] = {};
		fread(temp_height, sizeof(GE_BYTE), 4, file);
		png.IHDR.height = read32bitInt(temp_height);
		//Slow printing
		fprintf(stdout, "Image Height: %d\n", png.IHDR.height);
	}

	//Read image bit depth
	fread(&png.IHDR.bitDepth, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image bit depth: %d\n", png.IHDR.bitDepth);

	//Read image colour type
	fread(&png.IHDR.colourType, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image colour type (refer to table): %d\n", png.IHDR.colourType);

	//Read image compression type
	fread(&png.IHDR.compressionMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image compression method (refer to table): %d\n", png.IHDR.compressionMethod);

	//Read image filter method
	fread(&png.IHDR.filterMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image filter method (refer to table): %d\n", png.IHDR.filterMethod);

	//Read image interlace method
	fread(&png.IHDR.interlaceMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image interlace method (refer to table): %d\n", png.IHDR.interlaceMethod);
#pragma endregion
	
	
	GE_BYTE buffer[300] = {};
	fread(buffer, sizeof(GE_BYTE), 300, file);
	for (int i = 0; i < 300; i++) {
		//fprintf(stdout, "0x%x\n", buffer[i]);
		fprintf(stdout, "%i: %c\n", i, (char)buffer[i]);
	}
	fputs("\nDone.", stdout);
	
	//Close filestream
	fclose(file);

	fputs("\nFile closed.\n", stdout);

	return 0; // success!
}