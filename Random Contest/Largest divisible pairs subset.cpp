//https://www.geeksforgeeks.org/largest-divisible-pairs-subset/
#include <bits/stdc++.h>

int largestDivisiblePairSubset(int i, int largerElement, std::vector<int>& v, int n, std::vector<std::vector<int>>& dp) {
	if (i == n)
		return 0;
	if (dp[i][largerElement] != -1)
		return dp[i][largerElement];
	if (v[i] % largerElement == 0) {
		dp[i][largerElement] = std::max(largestDivisiblePairSubset(i + 1, v[i], v, n,dp) + 1, largestDivisiblePairSubset(i + 1, largerElement, v, n,dp));
		return dp[i][largerElement];
	}
	dp[i][largerElement] = largestDivisiblePairSubset(i + 1, largerElement, v, n,dp);
	return dp[i][largerElement];
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> v(t);
	int max = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> v[i];
		if (v[i] > max)
			max = v[i];
	}
	std::sort(v.begin(), v.end());
	std::vector<std::vector<int>> dp(t, std::vector<int>(max + 1, -1));
	std::cout << largestDivisiblePairSubset(0, 1, v, t, dp);
}
