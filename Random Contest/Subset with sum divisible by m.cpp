//https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0
#include <bits/stdc++.h>

bool subsetSumDivM(int i, int target, int m, int n, std::vector<int>& elements,std::vector<std::vector<int>>& dp) {
	if (target < 0)
		return false;
	if (i == n)
		return target == 0 ? true : false;
	if (dp[i][target]) {
		return dp[i][target];
	}
	dp[i][target] = subsetSumDivM(i + 1, (target - (elements[i] % m)) % m, m, n, elements, dp) || subsetSumDivM(i + 1, target, m, n, elements, dp);
	return dp[i][target];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n;
		std::cin >> m;
		std::vector<int> elements(n);
		for (int j = 0; j < n; j++)
		{
			std::cin >> elements[j];
		}
		std::vector<std::vector<int>> dp(n, std::vector<int>(m+1));

		std::cout << subsetSumDivM(0, m, m, n, elements,dp) << std::endl;
	}
}
