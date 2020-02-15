#include <bits/stdc++.h>

std::vector<std::vector<int>> arrDp;
int n;

int max(int a, int b, int c) {
	return std::max(std::max(a, b), c);
}

int minConstPath(std::vector<std::vector<int>> arr, int r, int c) {
	if (r == n || c == n || c < 0) return 0;
	if (arrDp[r][c] != 0) return arrDp[r][c];
	arrDp[r][c] = arr[r][c] + max(minConstPath(arr, r + 1, c), minConstPath(arr, r + 1, c + 1), minConstPath(arr, r + 1, c - 1));
	return arrDp[r][c];
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		std::vector<std::vector<int>> arr(n, std::vector<int>(n));
		arrDp.clear();
		arrDp.resize(n, std::vector<int>(n));
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				std::cin >> arr[j][k];
			}
		}

		int max = 0;

		for (int i = 0; i < n; i++)
		{
			int temp = minConstPath(arr, 0, i);
			max = temp > max ? temp : max;
		}
		std::cout << max << std::endl;
	}
	return 0;
};
