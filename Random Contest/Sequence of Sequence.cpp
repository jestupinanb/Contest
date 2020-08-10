#include <bits/stdc++.h>

int seqOfSeq(int m, int n, std::vector<std::vector<int>>& dp) {
	if (n == 0)
		return 1;
	if (m == 0)
		return 0;
	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	dp[m][n] = seqOfSeq(m / 2, n - 1, dp) + seqOfSeq(m - 1, n, dp);
	return dp[m][n];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> m >> n;
		std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, -1));
		std::cout << seqOfSeq(m, n, dp) << std::endl;
	}
}
