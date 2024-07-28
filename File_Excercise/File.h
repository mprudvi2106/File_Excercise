#include<iostream>
#include<fstream>
#include<string>
#include<map>
#define _CRT_SECURE_NO_WARNINGS

class FileOperations
{
public:
	//FileOperations();
	//~FileOperations();
	void setSize(int);
	int getSize();
	void setNodeid(unsigned int);
	unsigned int getNodeId();
	void setResultValue(float);
	float getResultValue();
private:
	int size_;
	unsigned int nodeId_;
	float resultValue_;

};
