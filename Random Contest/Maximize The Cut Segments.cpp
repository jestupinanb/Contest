//https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <bits/stdc++.h>

int max(int a, int b, int c) {
	return std::max(a, std::max(b, c));
}

int maximizeTheCutSegments(int n,int x,int y,int z,std::vector<int>& dp) {
	if (n == 0)
		return 0;
	if (n<0) {
		return INT_MIN;
	}
	if (dp[n]!=-1) {
		return dp[n];
	}
	dp[n] = 1 + max(maximizeTheCutSegments(n - x, x, y, z,dp), maximizeTheCutSegments(n - y, x, y, z,dp), maximizeTheCutSegments(n - z, x, y, z,dp));
	return dp[n];
}

int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		std::cin >> n;
		int x, y, z;
		std::cin >> x >> y >> z;
		std::vector<int> dp(n+1,-1);
		std::cout << maximizeTheCutSegments(n, x, y, z,dp)<<std::endl;
	}
}
