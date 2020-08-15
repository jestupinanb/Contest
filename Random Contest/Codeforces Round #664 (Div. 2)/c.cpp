//https://codeforces.com/contest/1395/problem/C
#include <bits/stdc++.h>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(m);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		std::cin >> b[i];
	}
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = a[i] & b[j];
		}
	}

	int rta = -1;
	
	for (int k = 0; k < 512 && rta == -1; k++)
	{
		bool cumple = false;
		for (int i = 0; i < n && rta == -1;i++)
		{
			cumple = false;
			for (int j = 0; j < m && rta == -1; j++)
			{
				if ((k | dp[i][j]) == k) {
					cumple = true;
				}
			}
			if (!cumple) {
				break;
			}
		}
		if (cumple) {
			rta = k;
		}
	}

	std::cout << rta;
}

