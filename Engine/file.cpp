#include "file.h"

#include <assert.h>
#include <stdlib.h>

//File buffering modes
//TODO: Not used yet
#define GE_FILE_BUFFER_MODE _IOFBF
#define GE_FILE_BUFFER_SIZE (4096)

//On starting the current active files should always be 0
GE_BYTE OutputFile::_activeOpenFiles = 0;

OutputFile::OutputFile(GE_STR filepath)
{
	//Most architectures don't allow too many files to be open at once
	assert(OutputFile::_activeOpenFiles < FOPEN_MAX);

	//Create
	_path = filepath;
	_file = new FILE();

	errno_t err = fopen_s(&_file, _path, "w");

	if (err != 0) { perror("Could not open output file");  return; } //TODO: error handling

	//Inc
	OutputFile::_activeOpenFiles++;
}

//Clean up
void OutputFile::Close()
{
	if (fclose(_file) == EOF)
	{
		printf("Failed"); //TODO: Use throw
	}

	//Remove
	_file = nullptr;

	//Dec
	OutputFile::_activeOpenFiles--;
}
OutputFile::~OutputFile() { if (_file != nullptr) { this->Close(); } }

// Should check if this->_file == nullptr, not done to save performance
void OutputFile::Write(GE_STR text) { fputs(text, _file); }
void OutputFile::WriteC(GE_CHAR text) {	fputc(text, _file); }
void OutputFile::WriteLine(GE_STR text, GE_CHAR end)
{
	this->Write(text);
	this->WriteC(end);
}

//Getters
GE_BYTE OutputFile::GetOpenFileCount() { return OutputFile::_activeOpenFiles; }
GE_STR OutputFile::GetPath() const { return this->_path; }