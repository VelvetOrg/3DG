#include "pngreader.h"

int main(int argc, char** argv)
{	
	
	

	/*

	for (int i = 0; i < 8; i++) {
		printf("0x%x", header[i]);
	}

	int character;

	while ((character = fgetc(file)) != EOF) {
		printf("0x%x", character);
	}*/
	
	/*
	GE_BYTE header[100] = {};
	
	fread(header, 1, 100, file);

	printf("Header read as: %d\n", header);

	*/


	PNG image;
	read("C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\PNG-Gradient.png", image);
	//read("C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\GridSizeFour.png", image);
	//read("C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\PLTE-Test-Images\\1.png", image);
	//read("C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\PLTE-Test-Images\\6.png", image);

	
	getchar();
	
	return 0;
}