#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	std::cin >> n;
	std::vector<int> minNumCoin(n + 1);
	std::vector<int> money = { 1,3,4 };
	minNumCoin[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < 3; j++)
		{
			if (i - money[j] >= 0) {
				min = std::min(min, minNumCoin[i-money[j]] + 1);
			}
		}
		minNumCoin[i] = min;
	}

	std::cout << minNumCoin[n] << '\n';

	return 0;
}
