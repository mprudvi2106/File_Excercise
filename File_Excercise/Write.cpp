#pragma once
#include"Write.h"

BinaryFileWriting::BinaryFileWriting(const char* FileName)
{
	OutPutFile.open(FileName, std::ios::out | std::ios::binary);
	if(!OutPutFile.is_open())
	{
		std::cout << "Error: File is not opening" << std::endl;
	}
}

void BinaryFileWriting::WriteBegin()
{
	char begin_Keyword[256] = "*begin";
	OutPutFile.write(begin_Keyword, sizeof(begin_Keyword));
}

void BinaryFileWriting::WriteSizeOfNodes(int NodeSize)
{
	char buffer[256];
	sprintf_s(buffer,  "%d", NodeSize);
	OutPutFile.write(buffer, sizeof(buffer));
}

void BinaryFileWriting::WriteData(const std::map<unsigned int, float>& dataMap)
{
	for (auto it = dataMap.begin(); it != dataMap.end(); ++it)
	{
		//unsigned int nodeId = it->first;
		//float resultValue = it->second;

		char buffer[256];
		sprintf_s(buffer, "%u, %f", it->first, it->second);

		OutPutFile.write((buffer), sizeof(buffer));
		//OutPutFile.write(reinterpret_cast<const char*>(&resultValue), sizeof(resultValue));
	}
}

void BinaryFileWriting::WriteEnd()
{
	char end_keyword[256] = "*end";
	OutPutFile.write(end_keyword, sizeof(end_keyword));
}

BinaryFileWriting::~BinaryFileWriting()
{
	if (OutPutFile.is_open())
	{
		OutPutFile.close();
	}
}