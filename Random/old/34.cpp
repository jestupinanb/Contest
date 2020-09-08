#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> b(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long sum = 0;
	int iPositives = n;

	for (int i = n - 1; i >= 0; i--)
	{
		sum += (long long)a[i] * b[i];
		iPositives = i;
	}

	std::cout << sum << '\n';
	return 0;
}
