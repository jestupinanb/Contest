//https://www.geeksforgeeks.org/ugly-numbers/
#include <iostream>
#include <bits/stdc++.h>

int main()
{
	std::vector<long long> dp(1);
	dp[0] = 1;
	long long i2 = 0;
	long long i3 = 0;
	long long i5 = 0;
	for (int i = 2; dp.size() < 1e4; i *= 2)
	{
		long long size = dp.size();
		long long next_mult_2 = 2 * dp[i2];
		long long next_mult_3 = 3 * dp[i3];
		long long next_mult_5 = 5 * dp[i5];
		long long next_min = std::min(std::min(next_mult_2, next_mult_3), next_mult_5);
		dp.push_back(next_min);
		while (2 * dp[i2] <= next_min) {
			i2++;
		}
		while (3 * dp[i3] <= next_min) {
			i3++;
		}
		while (5 * dp[i5] <= next_min) {
			i5++;
		}
	}
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int val;
		std::cin >> val;
		std::cout << dp[val-1]<<std::endl;
	}
	return 0;
}
