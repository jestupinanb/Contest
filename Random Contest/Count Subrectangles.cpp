//https://codeforces.com/problemset/problem/1323/B
#include <bits/stdc++.h>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	std::vector<int> b(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> b[i];
	}
	std::vector<int> aCount(n+1);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0) {
			int posi = i;
			for (i; i < n && a[i] != 0; i++) {
				for (int j = 0; j <= i-posi; j++)
				{
					aCount[j + 1]++;
				}
			}
		}
	}
	std::vector<int> bCount(m+1);
	for (int i = 0; i < m; i++)
	{
		if (b[i] != 0) {
			int posi = i;
			for (i; i < m && b[i] != 0; i++) {
				for (int j = 0; j<=i-posi; j++)
				{
					bCount[j+1]++;
				}
			}
		}
	}
	int aSize = aCount.size();
	long long subAreaK = 0;
	for (int i = 1; i < aSize; i++)
	{
		if (k%i==0 && k/i<=m) {
			subAreaK += aCount[i] * bCount[k / i];
		}
	}
	std::cout << subAreaK;
}
