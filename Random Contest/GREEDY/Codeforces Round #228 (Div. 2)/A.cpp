#include <bits/stdc++.h>

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
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i + 1] != v[i]) {
			v[i + 1] = v[i + 1] - v[i];
			sort(v.begin(), v.end());
			i = n-1;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
	}
	std::cout << sum;
}
