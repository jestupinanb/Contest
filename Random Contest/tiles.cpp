//https://www.geeksforgeeks.org/tiling-problem/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

long long waysTileFloor(int w, std::vector<long long>& dp) {

	if (w == 1) {
		return 1;
	}
	if (w == 2) {
		return 2;
	}
	if (dp[w] != -1) {
		return dp[w];
	}
	dp[w] = waysTileFloor(w - 1, dp) + waysTileFloor(w - 2, dp);
	return dp[w];
}

int main()
{
	//std::freopen("input.txt", "rt", stdin);
	//std::freopen("output.txt", "wt", stdout);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int w;
		std::cin >> w;
		std::vector<long long> dp(w+1,-1);
		std::cout << waysTileFloor(w, dp) << std::endl;
	}
}
