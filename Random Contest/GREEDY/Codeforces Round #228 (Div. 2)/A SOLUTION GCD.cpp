#include <bits/stdc++.h>

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	sort(v.begin(), v.end());

	int gcdv = v[v.size() - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		gcdv = gcd(gcdv, v[i]);
	}
	std::cout << gcdv * v.size();
}
