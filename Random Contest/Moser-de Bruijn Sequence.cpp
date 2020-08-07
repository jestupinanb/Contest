#include <bits/stdc++.h>

int moserDeBrujin(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	std::vector<int> dp(n);
	dp[0] = 0;
	dp[1] = 1;
	int lastPow4 = 1;
	int lastElement = 2;
	for (int i = 0; lastElement < n; i++)
	{
		lastPow4 *= 4;
		int size = lastElement;
		for (int i = 0; i < size && lastElement<n; i++)
		{
			dp[lastElement] = lastPow4 + dp[i];
			lastElement++;
		}
	}	
	return dp[n-1];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 1; i <= t; i++)
	{
		std::cout << moserDeBrujin(i)<<" ";
	}
}
