//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0
#include <bits/stdc++.h>

int MOD_VAL = 1000000007;

int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		long long fib_0 = 1;
		long long fib_1 = 1;
		for (int i = 3; i <= n; i++)
		{
			long long temp = fib_0 + fib_1;
			fib_0 = fib_1 % MOD_VAL;
			fib_1 = temp % MOD_VAL;
		}
		std::cout << fib_1<<std::endl;
	}
}
