#pragma once
#include"File.h"

//FileOperations::FileOperations() :size_(1), nodeId_(1), resultValue_(1.2)
//{
//
//}
//
void FileOperations::setSize(int size)
{
	size_ = size;
}

int FileOperations::getSize()
{
	return size_;
}

void FileOperations::setNodeid(unsigned int nodeId)
{
	nodeId_ = nodeId;
}

unsigned int FileOperations::getNodeId()
{
	return nodeId_;

}

void FileOperations::setResultValue(float value)
{
	resultValue_ = value;
}

float FileOperations::getResultValue()
{
	return resultValue_;
}

//FileOperations::~FileOperations()
//{
//
//}