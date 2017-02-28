#include "file.h"

int main(int argc, char** argv)
{
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

	getchar();
	
	return 0;
}