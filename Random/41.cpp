#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int bs(int l, int r, int target, std::vector<int>& a) {
	if (l <= r) {
		int m = (r - l) / 2 + l;
		if (a[m] == target) {
			return m;
		}
		if (a[m] < target) {
			return bs(m + 1, r, target, a);
		}
		if (a[m] > target) {
			return bs(l, m - 1, target, a);
		}
	}
	return -1;
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		int val;
		std::cin >> val;
		std::cout << bs(0, n - 1, val, a) << ' ';
	}
	return 0;
}
