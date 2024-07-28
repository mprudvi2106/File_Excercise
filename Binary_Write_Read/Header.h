#include<iostream>
#include<fstream>
#include<string>

class binary_Write_read
{
private:
	char begin_, end_;
	int size_;
	unsigned int nodeid_;
	float resultvalue_;
public:
	char getbegin_(char);
	char getend_(char);
	int getsize_(int);
	unsigned int getnodeid_(unsigned int);
	float getresultvalue(float);

};
