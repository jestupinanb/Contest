//https://practice.geeksforgeeks.org/problems/ncr/0
#include <bits/stdc++.h>

const int e9 = 1e9+7;

std::vector<std::vector<int>> arr;

int c(long long n, long long r) {
	if (n == r || r == 0) return 1;
	if (arr[n][r]) return arr[n][r];
	arr[n][r] = (c(n - 1, r - 1) % e9 + c(n - 1, r) % e9) % e9;
	return arr[n][r];
}

int main() {
	int t, n, r;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		std::cin >> r;
		arr.clear();
		arr.resize(n+1, std::vector<int>(r+1));
		if(r>n)
			std::cout << 0 << '\n';
		else std::cout << c(n, r) << '\n';
	}
	return 0;
};
