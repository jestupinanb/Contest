#include <bits/stdc++.h>

int max(int a, int b, int c) {
	return std::max(std::max(a, b), c);
}

int LCS(std::string& str1, std::string& str2, std::string& str3, int i, int j, int k, std::vector<std::vector<std::vector<int> > >& dp) {
	if (str1.size() <= i || str2.size() <= j || str3.size() <= k)
		return 0;
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	if (str1[i] == str2[j] && str2[j] == str3[k]) {
		dp[i][j][k] = 1 + LCS(str1, str2, str3, i + 1, j + 1, k + 1, dp);
		return dp[i][j][k];
	}
	dp[i][j][k] = max(LCS(str1, str2, str3, i + 1, j, k, dp), LCS(str1, str2, str3, i, j + 1, k, dp), LCS(str1, str2, str3, i, j, k + 1, dp));
	return dp[i][j][k];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		std::string str1, str2, str3;
		std::cin >> str1 >> str2 >> str3;
		std::vector<std::vector<std::vector<int> > > dp(a, std::vector<std::vector<int> >(b, std::vector<int>(c, -1)));
		std::cout << LCS(str1, str2, str3, 0, 0, 0, dp) << std::endl;
	}
}
