#include <iostream>
#include <fstream>
#include <vector.hpp>
#include <vector>

int main()
{
	std::ofstream outf("mytest.txt");
	outf << " -------------------  TESTING VECTOR  -------------------" << std::endl;

	ft::vector<int> first_vector(10, 100);
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft::vector<int> vector2(array, array + 10);

	outf << "Array content: " << std::endl;
	// ft::vector<int>::iterator it1;

}

int main2()
{
	ft::vector<int> v1;
	ft::vector<int> v2(5);
	ft::vector<int> v3(5, 100);
	ft::vector<int> v4(v3.begin(), v3.end());
	ft::vector<int> v5(v4);

	std::cout << "v1: ";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << " ";
	std::cout << std::endl;

	std::cout << "v2: ";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << " ";
	std::cout << std::endl;

	std::cout << "v3: ";
	for (size_t i = 0; i < v3.size(); i++)
		std::cout << v3[i] << " ";
	std::cout << std::endl;

	std::cout << "v4: ";
	for (size_t i = 0; i < v4.size(); i++)
		std::cout << v4[i] << " ";
	std::cout << std::endl;

	std::cout << "v5: ";
	for (size_t i = 0; i < v5.size(); i++)
		std::cout << v5[i] << " ";
	std::cout << std::endl;

	return 0;
}