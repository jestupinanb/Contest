//https://www.geeksforgeeks.org/newman-shanks-williams-prime/
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int sn0 = 1;
	int sn1 = 1;
	for (int i = 2; i <= n; i++)
	{
		int sn = 2 * sn1 + sn0;
		sn0 = sn1;
		sn1 = sn;
	}
	std::cout << sn1;
}
