//https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
#include <bits/stdc++.h>

int maxSumBitonic(std::vector<int> a, int n) {
	std::vector<int> lr(n);
	std::vector<int> rl(n);
	for (int i = 0; i < n; i++)
	{
		lr[i] = a[i];
		rl[i] = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && lr[j] + a[i] > lr[i]) {
				lr[i] = lr[j] + a[i];
			}
		}
	}

	
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j >= i; j--)
		{
			if (a[i]>a[j] && a[i] + rl[j] > rl[i]) {
				rl[i] = a[i] + rl[j];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		max = std::max(lr[i] + rl[i] - a[i],max);
	}
	return max;
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a[i];
			if (max < a[i])
				max = a[i];
		}
		std::cout << maxSumBitonic(a, n) << std::endl;
	}
}
