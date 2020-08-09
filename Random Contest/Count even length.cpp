//https://practice.geeksforgeeks.org/problems/count-even-length/0
#include <bits/stdc++.h>

int MOD_VAL = 1e9+7;

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<long long> sol(n+1);
		sol[0] = 1;
		sol[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j >= 1; j--)
			{
				sol[j] = (sol[j]+sol[j - 1])%MOD_VAL;
			}
		}
		long long count = 0;
		for (int i = 0; i <= n; i++)
		{
			count = (count+(sol[i] * sol[i])%MOD_VAL)%MOD_VAL;
		}
		std::cout << count<<std::endl;
	}
}
