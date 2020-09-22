#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

//i==n
int partitionSouv(int f1, int f2, int total, int i, std::vector<int>& a, std::vector<std::vector<std::vector<int>>>& dp) {
	if (i == -1) {
		return f1 == f2 && f2 == total - (f2 + f1);
	}
	if (dp[f1][f2][i] != -1)
		return dp[f1][f2][i];
	return dp[f1][f2][i] = partitionSouv(f1 + a[i], f2, total, i - 1, a, dp) || partitionSouv(f1, f2 + a[i], total, i - 1, a, dp) || partitionSouv(f1, f2, total, i - 1, a, dp);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	int total = 0;

	for (int i = 0; i < n; i++)
	{
		total += v[i];
	}

	std::vector<std::vector<std::vector<int>>> dp(600 + 1, std::vector<std::vector<int>>(600 + 1, std::vector<int>(n, -1)));
	std::cout << partitionSouv(0, 0, total, n - 1, v, dp) << '\n';
	return 0;
}

