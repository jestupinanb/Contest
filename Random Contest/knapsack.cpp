//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>

std::vector<std::vector<int>> dp;

int knapsack(int i, int w,std::vector<int> &items,std::vector<int> &weights) 
{
	if (w == 0)
		return 0;
	if (i == -1)
		return 0;
	//std::cout << "knapsack(" << i+1 << "," << w << ")" << std::endl;
	if (dp[i][w] != 0) {
		//std::cout << "NO calculated" << std::endl;
		return dp[i][w];
	}
	//std::cout << "Calculated" << std::endl;
	if (w - weights[i] < 0) {
		dp[i][w] = knapsack(i - 1, w, items, weights);
		return dp[i][w];
	}
	dp[i][w] = std::max(
		knapsack(i - 1, w, items, weights), knapsack(i - 1, w - weights[i], items, weights) + items[i]);
	return dp[i][w];
}

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i <t; i++)
	{
		dp.clear();
		int n,w;
		std::cin >> n;
		std::vector<int> items(n);
		std::vector<int> weights(n);
		std::cin >> w;
		dp.resize(n, std::vector<int>(w+1));
		for (int i = 0; i < n; i++)
		{
			std::cin >> items[i];
		}
		for (int i = 0; i < n; i++)
		{
			std::cin >> weights[i];
		}
		std::cout << knapsack(n-1, w, items, weights)<<std::endl;
	}
	return 0;
}
