#pragma once
#include"Write.h"

class BinaryFileReading
{
public:
	BinaryFileReading(const char* FileName);
	~BinaryFileReading();
	bool readBegin();
	int readSizeOfNodes();
	std::map<unsigned int, float> readNodeData();
	bool readEndKeyword();
	std::map<unsigned int, float> readFile();

private:
	std::fstream InFile;
};