//https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one/0
#include <bits/stdc++.h>

int LSDBAI1(int i, int lv, std::vector<int>& v, int vSize, std::vector<std::vector<int>>& dp,int def) {
	if (i == vSize)
		return 0;
	if (dp[i][lv] != -1)
		return dp[i][lv];
	if (lv == def || std::abs(v[i] - lv) == 1)
		return dp[i][lv] = std::max(1 + LSDBAI1(i + 1, v[i], v, vSize, dp,def), LSDBAI1(i + 1, lv, v, vSize, dp,def));
	return dp[i][lv] = LSDBAI1(i + 1, lv, v, vSize, dp,def);
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
		int max = 0;
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[j];
			max = std::max(max, a[j]);
		}
		std::vector<std::vector<int>> dp(n, std::vector<int>(max + 1 + 1, -1));
		std::cout << LSDBAI1(0, max + 1, a, n, dp,max+1) << std::endl;
	}
}
