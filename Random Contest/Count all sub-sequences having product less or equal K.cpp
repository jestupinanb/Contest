#include <bits/stdc++.h>

int countProductLessK(int i, int mult, std::vector<int>& v, int k, int vSize,std::vector<std::vector<int>>& dp) {
	if (i == vSize)
		return 0;
	if (dp[i][mult])
		return dp[i][mult];
	if (mult*v[i]<=k)
		return dp[i][mult] = 1 + countProductLessK(i + 1, v[i] * mult, v, k, vSize,dp) + countProductLessK(i + 1, mult, v, k, vSize,dp);
	else
		return dp[i][mult] = countProductLessK(i + 1, mult, v, k, vSize,dp);
}

int main()
{
	int t;
	std::cin >> t;
	std::vector<int> v(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> v[i];
	}
	int k;
	std::cin >> k;
	std::vector<std::vector<int>> dp(t, std::vector<int>(k + 1));
	std::cout<<countProductLessK(0, 1, v, k,t,dp);
}
