#include "pngreader.h"
//Files and printing
#include <stdio.h>

#define filecurrentpos SEEK_CUR

int read(const char* filepath, PNG &png) {
	
#pragma region Open file
	FILE* file = nullptr; //Filestream
	//Stores the error code
	errno_t	error = fopen_s(&file, filepath, "rb");

	//Check for errors with opening filestream
	if (error != 0x0) {
		//Close file on failure
		fputs("File could not be opened.\n", stderr);
		return -1; // error: file could not be opened
	}
	else {
		fputs("File opened.\n", stdout);
	}
#pragma endregion

#pragma region Read IHDR
	
	
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
		fprintf(stdout, "\nImage Width: %d\n", png.IHDR.width);

		//Read image height
		GE_BYTE temp_height[4] = {};
		fread(temp_height, sizeof(GE_BYTE), 4, file);
		png.IHDR.height = read32bitInt(temp_height);
		//Slow printing
		fprintf(stdout, "Image Height: %d\n", png.IHDR.height);
	}

	//Read image bit depth
	fread(&png.IHDR.bitDepth, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "\nImage bit depth: %d\n", png.IHDR.bitDepth);

	//Read image colour type
	fread(&png.IHDR.colourType, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image colour type: %d\n", png.IHDR.colourType);

	//Read image compression type
	fread(&png.IHDR.compressionMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image compression method: %d\n", png.IHDR.compressionMethod);

	//Read image filter method
	fread(&png.IHDR.filterMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image filter method: %d\n", png.IHDR.filterMethod);

	//Read image interlace method
	fread(&png.IHDR.interlaceMethod, sizeof(GE_BYTE), 1, file);
	fprintf(stdout, "Image interlace method: %d\n", png.IHDR.interlaceMethod);
#pragma endregion
	
	//If the image is greyscale, or greyscale with alpha: no PLTE chunk is present
	//if ((png.IHDR.colourType == PNG_COLOUR_TYPE_BW || (png.IHDR.colourType == PNG_COLOUR_TYPE_BWA)) {

	//}
	
	//TODO: Remove test scenario
	//TODO: Add IDAT chunk reading
	
	int seekBy = (png.IHDR.colourType == PNG_COLOUR_TYPE_RGB) ? 3 : ((png.IHDR.colourType == PNG_COLOUR_TYPE_RGBA) ? 4 : -1);

#pragma region Check for PLTE chunk
	
	//Check if PNG can have PLTE chunk
	if((png.IHDR.colourType == PNG_COLOUR_TYPE_BW) || (png.IHDR.colourType == PNG_COLOUR_TYPE_BWA)) {
		//Slow printing
		fputs("\nImage will not have a PLTE chunk.\n", stdout);
	}
	else {
		
		//Var to temporily hold value of next byte
		GE_BYTE temp_sig_check_buf = NULL;
		//Continually seek forward, skipping all of Adobe's shit until we reach the beginning of the PLTE chunk
		while (temp_sig_check_buf != plte_signature[0]) { 
			fread((void*)(&temp_sig_check_buf), sizeof(GE_BYTE), 1, file);
		};
			
		//New scope
		{
			GE_BYTE temp_sig_check_buf[3] = {};
			fread(temp_sig_check_buf, sizeof(GE_BYTE), 3, file);
			if (memcmp(temp_sig_check_buf, "LTE", 3) == 0x0) {
				memcpy(png.PLTE.type, "PLTE", 4);
			}
			else if (memcmp(temp_sig_check_buf, "LT", 2) == 0x0) {
				memcpy(png.PLTE.type, "PLT", 4);
				fseek(file, -1, SEEK_CUR);
			}
			else {
				memcpy(png.PLTE.type, "N/A", 3); 
				fseek(file, -4, SEEK_CUR); // -4 because we seek back 3 bytes for which we used to check for LTE and 1 more byte because the while loop goes one byte extra
			}
		}
			
		//Seek back one byte because it will have gone one byte too far
		//fseek(file, -1, SEEK_CUR);
		//fseek(file, -2, SEEK_CUR);
		fputs("\nChunk Type: ", stdout);
		for (int i = 0; i < (sizeof(png.PLTE.type) / sizeof(GE_UCHAR)); i++) {
			printf("%c", (char)png.PLTE.type[i]);
		}

		/*
		//Temporary until I can figure out another way
		{
			GE_UCHAR temp_buf[4] = {};
			fread(temp_buf, sizeof(GE_UCHAR), 4, file);
			if ((memcmp(temp_buf, "PLTE", 4) == 0x0) || (memcmp(temp_buf, "PLT", 3) == 0x0)) {
				char* str = "PLTE";
				memcpy(png.PLTE.type, str, 4);
				fputs("\nChunk Type: ", stdout);
				for (int i = 0; i < 4; i++) {
					printf("%c", (char)png.PLTE.type[i]);
				}
				fputs("\n", stdout);
			}
			else {
				fputs("No PLTE chunk present.\n", stdout);
			}

		}
		*/
	}

#pragma endregion

#pragma region Fill PLTE
	if (memcmp(png.PLTE.type, "PLTE", 4) == 0x0) {
		fseek(file, 4, filecurrentpos);
		fseek(file, 51, filecurrentpos);
	}
#pragma endregion


	fputs("\n\n\n\n", stdout);
	{
		GE_BYTE array[500] = {};
		fread(array, sizeof(GE_BYTE), 300, file);
		for (int i = 0; i < 500; i++) {
			fprintf_s(stdout, "%u ", array[i]);
		}
	}

	//Close the filestream once we are done
	fclose(file);

	fputs("\nFile closed.\n", stdout);

	return 0; // success!
}