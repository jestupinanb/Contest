//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>

int LIS(std::vector<int>& v, int i, int max, std::vector<std::vector<int>>& dp) {
	if (i == v.size())
		return 0;
	if (dp[i][max+1] != -1)
		return dp[i][max+1];
	if (v[i] > max) {
		return dp[i][max+1] = std::max(1 + LIS(v, i + 1, v[i], dp), LIS(v, i + 1, max, dp));
	}
	return dp[i][max+1] = LIS(v, i + 1, max, dp);
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		int maxVal = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a[i];
			if (maxVal < a[i])
				maxVal = a[i];
		}
		std::vector<std::vector<int>> dp(n, std::vector<int>(maxVal + 2, -1));
		std::cout << LIS(a, 0, -1, dp) << std::endl;
	}
}
