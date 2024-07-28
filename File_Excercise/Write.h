#pragma once
#include"File.h"

class BinaryFileWriting
{
private:
	std::fstream OutPutFile;
public:
	BinaryFileWriting(const char* FileName);
	void WriteBegin();
	void WriteSizeOfNodes(int NodeSize);
	void WriteData(const std::map<unsigned int, float>& dataMap);
	void WriteEnd();
	~BinaryFileWriting();

};