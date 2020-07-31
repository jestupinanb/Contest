//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <bits/stdc++.h>

bool subsetSumProblem(int i,int sum,int n,int total,std::vector<int>& elements,std::vector<std::vector<int>>& dp) {
	if (i==n)
		return 2 * sum == total ? true : false;
	if (2 * sum >= total) 
		return 0;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	dp[i][sum] = subsetSumProblem(i + 1, sum + elements[i], n, total, elements, dp) || subsetSumProblem(i + 1, sum, n, total, elements, dp);
	return dp[i][sum];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> elements(n);
		int total = 0;
		for (int j = 0; j < n; j++)
		{
			std::cin >> elements[j];
			total += elements[j];
		}
		std::vector<std::vector<int>> dp(n,std::vector<int>(total / 2 + 1,-1));
		std::cout<<(subsetSumProblem(0, 0, n,total, elements,dp) ? "YES":"NO")<<std::endl;
	}
}
