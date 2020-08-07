#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::cout << (n / 2) + 1<<std::endl;
	}
}
