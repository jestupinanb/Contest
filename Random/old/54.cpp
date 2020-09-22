#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int lcs(int i, int j, std::vector<int>& a, std::vector<int>& b, int n, int m, std::vector<std::vector<int>>& dp) {
	if (i == n || j == m) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (a[i] == b[j]) {
		return dp[i][j] = 1 + lcs(i + 1, j + 1, a, b, n, m,dp);
	}
	else {
		return dp[i][j] = std::max(lcs(i + 1, j, a, b, n, m,dp), lcs(i, j + 1, a, b, n, m,dp));
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	std::vector<int> b(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> b[i];
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
	std::cout << lcs(0, 0, a, b, n, m, dp);

	return 0;
}

