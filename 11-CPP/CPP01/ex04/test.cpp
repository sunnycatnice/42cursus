#include <iostream>
#include <fstream>

int main()
{
	int i = 0;
	int j = 0;

	std::ofstream  file;

	std::string str = "bisogna fare il fare replace di xxx ciao";
	std::string from = "ciao";
	std::string to = "NUOVO";

	file.open("file.txt");
	while(str[i])
	{
		if (str.substr(i, from.length()) == from)
		{
			j = 0;
			while(to[j])
			{
				file << to[j];
				i++; j++;
			}
			if (str[i])
				file << str[i - 1];
		}
		else
			file << str[i++];
	}	
}