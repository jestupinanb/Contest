#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

//i==n
int goldBar(int w, int i, std::vector<int>& a, std::vector<std::vector<int>>& dp) {
	if (i == -1)
		return 0;
	if (dp[w][i] != -1)
		return dp[w][i];
	if (w - a[i] >= 0)
		return dp[w][i] = std::max(a[i] + goldBar(w - a[i], i - 1, a, dp), goldBar(w, i - 1, a, dp));
	else
		return dp[w][i] = goldBar(w, i - 1, a, dp);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int w, n;
	std::cin >> w >> n;
	std::vector<int> wi(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> wi[i];
	}
	std::vector<std::vector<int>> dp(w + 1, std::vector<int>(n, -1));
	std::cout << goldBar(w, n - 1, wi, dp) << '\n';
	return 0;
}

