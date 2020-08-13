//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <bits/stdc++.h>

int LCS(std::string& str1, std::string& str2, int i,int j,std::vector<std::vector<int>>& dp) {
	if (str1.size() <= i)
		return 0;
	if (str2.size() <= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (str1[i] == str2[j]) {
		dp[i][j] = 1 + LCS(str1, str2, i + 1, j + 1, dp);
		return dp[i][j];
	}
	dp[i][j] = std::max(LCS(str1, str2, i + 1, j, dp), LCS(str1, str2, i, j + 1, dp));
	return dp[i][j];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		std::cin >> a >> b;
		std::string str1, str2;
		std::cin >> str1 >> str2;
		std::vector<std::vector<int>> dp(a,std::vector<int>(b,-1));
		std::cout<<LCS(str1, str2, 0, 0,dp)<<std::endl;
	}
}
