#include <bits/stdc++.h>

std::vector<std::vector<int>> arrDp;

int coinChange(std::vector<int> arr, int m, int n) {
	if (n == 0) {
		return 1;
	}
	if (n < 0)
		return 0;
	if (m < 1)
		return 0;
	if (arrDp[m - 1][n - 1] != 0)
		return arrDp[m - 1][n - 1];
	arrDp[m - 1][n - 1] = coinChange(arr, m - 1, n) + coinChange(arr, m, n - arr[m - 1]);
	return arrDp[m - 1][n - 1];
}

int main() {
	int t, m, n;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> m;
		std::vector<int> arr(m);
		for (int j = 0; j < m; j++)
		{
			std::cin >> arr[j];
		}
		std::cin >> n;

		arrDp.clear();
		arrDp.resize(m, std::vector<int>(n));

		std::vector<int> arr2;
		std::cout << coinChange(arr, m, n) << std::endl;
	}
	return 0;
};
