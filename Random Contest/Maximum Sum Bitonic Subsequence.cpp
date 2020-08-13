//https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
#include <bits/stdc++.h>

int incMaxSumBitonic(std::vector<int>& v, int i, int max, int vSize, std::vector<std::vector<int>>& dp) {
	if (i == vSize)
		return 0;
	if (dp[i][max] != -1)
		return dp[i][max];
	if (v[i] > max)
		return dp[i][max] = std::max(v[i] + incMaxSumBitonic(v, i + 1, v[i], vSize, dp), incMaxSumBitonic(v, i + 1, max, vSize, dp));
	return dp[i][max] = incMaxSumBitonic(v, i + 1, max, vSize, dp);
}

int decMaxSumBitonic(std::vector<int>& v, int i, int min, int vSize, std::vector<std::vector<int>>& dp) {
	if (i == vSize)
		return 0;
	if (dp[i][min] != -1)
		return dp[i][min];
	if (v[i] < min)
		return dp[i][min] = std::max(v[i] + decMaxSumBitonic(v, i + 1, v[i], vSize, dp), decMaxSumBitonic(v, i + 1, min, vSize, dp));
	return dp[i][min] = decMaxSumBitonic(v, i + 1, min, vSize, dp);
}

int maxSumBitonic(std::vector<int>& v, int vSize, int max) {
	std::vector<int> maxPos(vSize);
	std::vector<int> maxVal(vSize + 1);
	maxVal[0] = max+1;
	for (int i = 1; i <= vSize; i++)
	{
		std::vector<std::vector<int>> dpInc(vSize, std::vector<int>(max + 1, -1));
		maxPos[i - 1] = incMaxSumBitonic(v, 0, 0, i, dpInc);
		if (i==1||maxPos[i - 2] != maxPos[i - 1])
			maxVal[i] = v[i - 1];
		else
			maxVal[i] = maxVal[i - 1];
	}
	std::vector<int> minPos(vSize);


	for (int i = 0; i < vSize; i++)
	{
		std::vector<std::vector<int>> dpDec(vSize, std::vector<int>(max + 2, -1));
		minPos[i] = decMaxSumBitonic(v, i, maxVal[i], vSize, dpDec);
	}

	int maxBitonic = (maxPos[vSize - 1] > minPos[0]) ? maxPos[vSize - 1] : minPos[0];

	for (int i = 0; i < vSize - 1; i++)
	{
		if (maxBitonic < (maxPos[i] + minPos[i + 1])) {
			maxBitonic = maxPos[i] + minPos[i + 1];
		}
	}
	return maxBitonic;
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
		std::cout << maxSumBitonic(a, n, max) << std::endl;
	}
}
