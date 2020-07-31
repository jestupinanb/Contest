//https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
#include <bits/stdc++.h>

int VAL_MOD = 1e9 + 7;

long long waysPired(int i,std::vector<long long>& dp) {
	if (i==1) {
		return 1;
	}
	if (i == 2) {
		return 2;
	}
	if (dp[i]) {
		return dp[i];
	}
	dp[i] = (waysPired(i - 1, dp) + (((i - 1) * waysPired(i - 2, dp)) % VAL_MOD)) % VAL_MOD;
	return dp[i];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<long long> dp(n + 1);
		std::cout<<waysPired(n,dp)<<std::endl;
	}
}
