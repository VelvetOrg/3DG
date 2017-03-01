#include "file.h"
#include "pngdata.h"

int main(int argc, char** argv)
{	/*
	OutputFile file("engine.tlog");

	file.Write("Wrote a line to the file");
	file.WriteC('\t');
	file.WriteLine("Tabbed out meme");
	file.Write("Path is: "); file.Write(file.GetPath()); file.WriteC('\n');
	file.WriteLine(__FILE__);
	file.WriteLine(__FUNCTION__);
	
	GE_CHAR* buf = new GE_CHAR[4];
	Str::IntToStr(__LINE__, buf, 4);
	file.WriteLine(buf);
	DELETE_ARR(buf);
	*/

	/*FILE* file = nullptr;
	errno_t error = fopen_s(&file, "C:\\Users\\Ruchir Bapat\\Documents\\GitHub\\3DG\\Engine\\Assets\\testbed_image.png", "rb");
	printf("errorcode: %d\n", error);
	int val = 0;
	
	fseek(file, 8, SEEK_SET);
	for (int i = 0; i <= 4; i++) {
		val = fgetc(file);
		std::cout << val;

	}
	std::cout << "\nDone\n";
	//printf("\n\n%d ", (unsigned int)val);
	//std::cout << buffer << std::endl;
	do {
		//val = fgetc(file);
		val = fread(static_cast<FILE*>(file), 4, 4, file);
		//printf("%x ", (unsigned char)val);
		printf("%d ", (unsigned int)val);
		//std::cout << (unsigned char)val;
	} while (val != EOF);
	

	if (fclose(file) == EOF) {
		printf("\ncouldnt close file"); getchar();  return -99;
	}
	else {
		file = nullptr;
		printf("\nfile closed");
	}
	*/
	

	
	getchar();
	
	return 0;
}