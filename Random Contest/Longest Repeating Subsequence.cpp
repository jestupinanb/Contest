//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
#include <bits/stdc++.h>

int LRS(std::string& str,int i,int e,std::vector<std::vector<int>>& dp) {
	if (i == str.size() || i==e)
		return 0;
	if (dp[i][e] != -1)
		return dp[i][e];
	if (str[i] == str[e]) {
		dp[i][e] = 1 + LRS(str, i + 1, e + 1, dp);
		return dp[i][e];
	}
	dp[i][e] = std::max(LRS(str, i + 1, e, dp), LRS(str, i, e + 1, dp));
	return dp[i][e];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::string str;
		std::cin >> str;
		std::vector<std::vector<int>> dp(n, std::vector<int>(n,-1));
		std::cout<<LRS(str, 1, 0,dp)<<std::endl;
	}
}
