//https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
#include <bits/stdc++.h>

int max(int a, int b, int c) {
	return std::max(std::max(a, b), c);
}

int maxGold(int i, int j, int n, int m, std::vector<std::vector<int>> &gold,std::vector<std::vector<int>>& dp) {
	if (i >= n || i < 0) {
		return 0;
	}
	if (j >= m || j < 0) {
		return 0;
	}
	if (dp[i][j] != 0) {
		return dp[i][j];
	}
	dp[i][j] = gold[i][j] + max(maxGold(i + 1, j + 1, n, m, gold, dp), maxGold(i, j + 1, n, m, gold, dp), maxGold(i - 1, j + 1, n, m, gold, dp));
	return dp[i][j];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n;
		std::cin >> m;
		std::vector<std::vector<int>> gold(n, std::vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> gold[i][j];
			}
		}
		int max = 0;
		std::vector<std::vector<int>> dp(n, std::vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			int  gold_i = maxGold(i, 0, n, m, gold,dp);
			if (gold_i > max) {
				max = gold_i;
			}
		}
		std::cout << max << std::endl;
	}
}
