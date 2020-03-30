#include <bits/stdc++.h>

int main() {
	long long n, k, x;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> k >> x;
		std::cout << x + 9 * (k - 1)<<'\n';
	}
	/*
	//Codigo usado para saber que se tiene una formula
	for (int i = 0; i < 100; i++)
	{
		int itemp = i;
		while(itemp>= 10) {
			itemp = itemp / 10 + itemp % 10;
		}
		std::cout << "iteracion "<<i<<" value " <<itemp<<'\n';
	}
	*/
	return 0;
}
