#pragma once
#include"Write.h"
#include"Read.h"

int main(int argc, char* argv[])
{

	std::map<unsigned int, float> dataMap;
	FileOperations fileOps;
	const char* FileName = argv[1];
	BinaryFileWriting bWriting(FileName);
	int size;
	std::cout << "Enter the Size of node data" << std::endl;
	std::cin >> size;

	fileOps.setSize(size);
	unsigned int FirstNodeId;
	float FirstResultValue;
	std::cout << "Enter the First Node Id" <<  ":" << std::endl;
	std::cin >> FirstNodeId;
	std::cout << "Enter the result value for node"  << ":" << std::endl;
	std::cin >> FirstResultValue;

	fileOps.setNodeid(FirstNodeId);
	fileOps.setResultValue(FirstResultValue);
	dataMap[FirstNodeId] = FirstResultValue;


	unsigned int nodeId = 0;
	float resultValue = 0.0f;

	unsigned int nextKey;
	float nextResultValue;


	for (int i = 1; i < size; i++)
	{

		nodeId = FirstNodeId + 1;
		resultValue = FirstResultValue + 1;
		//std::cout << "Enter the Node Id" << i + 1 << ":" << std::endl;
		//std::cin >> nodeId;
		fileOps.setNodeid(nodeId);

		//std::cout << "Enter the result value for node" << i + 1 << ":" << std::endl;
		//std::cin >> resultValue;
		fileOps.setResultValue(resultValue);

		// storing data in the map
		dataMap[nodeId] = resultValue;
		nextKey = nodeId;
		nextResultValue = resultValue;
		FirstNodeId = nextKey;
		FirstResultValue = nextResultValue;
	}

	//BinaryFileWriting binaryFile(FileName);
	bWriting.WriteBegin();
	bWriting.WriteSizeOfNodes(size);
	bWriting.WriteData(dataMap);
	bWriting.WriteEnd();

	std::cout << "Binary file is created successfully" << std::endl;


	BinaryFileReading bReading(FileName);
	std::map<unsigned int, float> dataMap1 = bReading.readFile();
	unsigned int findNodeId;
	std::cout << "Enter the Node Id value to be found:;" << std::endl;
	std::cin >> findNodeId;
	unsigned int KeyToFind = static_cast<unsigned int> (findNodeId);
	auto it = dataMap.find(KeyToFind);
	if (it != dataMap.end())
	{
		std::cout << "Found node Id:" << KeyToFind << ", Value of the Node Id is:" << it->second << std::endl;

	}
	else
	{
		std::cout << "Key" << KeyToFind << " is not found" << std::endl;
	}
	return 0;
}