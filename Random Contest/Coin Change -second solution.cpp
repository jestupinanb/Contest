//https://practice.geeksforgeeks.org/problems/coin-change/0
#include <bits/stdc++.h>

int waysToMakeChange(int i, int cents, int m, std::vector<int>& a, std::vector<std::vector<int>>& dp) {
	if (i >= m || cents < 0) {
		return 0;
	}
	if (cents == 0) {
		return 1;
	}
	if (dp[i][cents] != -1) {
		return dp[i][cents];
	}
	dp[i][cents] = waysToMakeChange(i, cents - a[i], m, a, dp) + waysToMakeChange(i + 1, cents, m, a, dp);
	return dp[i][cents];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n;
		std::cin >> m;
		std::vector<int> a(m);
		for (int i = 0; i < m; i++)
		{
			std::cin >> a[i];
		}
		std::cin >> n;
		std::vector<std::vector<int>> dp(m, std::vector<int>(n+1,-1));
		std::cout << waysToMakeChange(0, n, m, a, dp) << std::endl;
	}
}
