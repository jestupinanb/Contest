//https://codeforces.com/contest/1395
#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int r, g, b, w;
		std::cin >> r >> g >> b >> w;
		int numOdd = 0;
		if (r % 2)
			numOdd++;
		if (g % 2)
			numOdd++;
		if (b % 2)
			numOdd++;
		if (w % 2)
			numOdd++;
		if (numOdd <= 1)
			std::cout << "YES"<<std::endl;
		else if(r>0 && g>0 && b>0){
			r = r - 1;
			g = g - 1;
			b = b - 1;
			w = w + 3;
			int numOddT = 0;
			if (r % 2)
				numOddT++;
			if (g % 2)
				numOddT++;
			if (b % 2)
				numOddT++;
			if (w % 2)
				numOddT++;
			if (numOddT <= 1)
				std::cout << "YES"<<std::endl;
			else {
				std::cout << "NO" << std::endl;
			}
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}

