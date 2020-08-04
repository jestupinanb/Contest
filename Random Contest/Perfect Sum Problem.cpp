//https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
#include <bits/stdc++.h>

int MOD_VALUES = int(1e9 + 7);

int perfectSum(int i, int sum, std::vector<int>& a, std::vector<std::vector<int>>& dp) {
	if (sum < 0) return 0;
	if (i == -1) {
		return sum == 0 ? 1 : 0;
	}
	if (dp[i][sum] != -1)
		return dp[i][sum];
	dp[i][sum] = (perfectSum(i - 1, sum - a[i], a, dp) + perfectSum(i - 1, sum, a, dp)) % MOD_VALUES;
	return dp[i][sum];
}

int main()
{
	int t;
	scanf("%d", &t);
	//std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		//std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			//std::cin >> a[i];
			scanf("%d", &a[i]);
		}
		int sum;
		//std::cin >> sum;
		scanf("%d", &sum);
		std::vector<std::vector<int>> dp(n, std::vector<int>(sum+1, -1));
		std::cout << perfectSum(n - 1, sum, a, dp) << std::endl;
	}
}
