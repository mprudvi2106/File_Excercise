#include"Header.h"

class write
{
public:
	write()
	{
		std::string filename;
		std::fstream inputputfile(filename, std::ios::in | std::ios::binary);

		if (!inputputfile.is_open())
		{
			std::cout << "Error:File is not opening" << std::endl;
		}
		//writing data into file
		for (int i = 0; i < size; i++)
		{
			inputputfile.write()
		}
	}
};