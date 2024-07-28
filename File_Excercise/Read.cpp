#pragma once
#include"Read.h"

BinaryFileReading::BinaryFileReading(const char* FileName)
{
	InFile.open(FileName, std::ios::in | std::ios::binary);
	if (!InFile.is_open())
	{
		std::cout << "Error: File is not opening" << std::endl;
	}
}
BinaryFileReading::~BinaryFileReading()
{
	if (InFile.is_open())
	{
		InFile.close();
	}
}

bool BinaryFileReading::readBegin()
{
	char begin_Keyword[256];
	InFile.read(begin_Keyword, sizeof(begin_Keyword));
	return std::strncmp(begin_Keyword, "*begin", 256) == 0;
}

int BinaryFileReading::readSizeOfNodes()
{
	int nodeSize;
	InFile.read(reinterpret_cast<char *>(&nodeSize), sizeof(nodeSize));
	return nodeSize;
}

std::map<unsigned int, float> BinaryFileReading::readNodeData()
{
	std::map<unsigned int, float> dataMap;
	int size = readSizeOfNodes();
	unsigned int nodeId = 0;
	float resultValue=0;
	//char buffer[256];
	for (int i = 0; i < size; ++i)
	{
		InFile.read(reinterpret_cast<char*>(&nodeId), sizeof(nodeId));
		InFile.read(reinterpret_cast<char*>(&resultValue), sizeof(resultValue));
		dataMap[nodeId] = resultValue;
	}
	return dataMap;
}

bool BinaryFileReading::readEndKeyword()
{
	char end_Keyword[256];
	InFile.read(end_Keyword, sizeof(end_Keyword));
	return std::strncmp(end_Keyword, "*end", 256) == 0;
}

std::map<unsigned int, float> BinaryFileReading::readFile()
{
	std::map<unsigned int, float> dataMap;
	if (readBegin())
		{
			dataMap = readNodeData();
			if (!readEndKeyword())
			{
				std::cerr << "Error: End Keyword Mismatch" << std::endl;
			}
		}
	return dataMap;
}