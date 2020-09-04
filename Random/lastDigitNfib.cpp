#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

long long nFib(int n) {
	if (n <= 1)
		return n;
	long long n_1 = 0;
	long long n_2 = 1;
	for (int i = 2; i <= n; i++)
	{
		long long temp = (n_1 + n_2)%10;
		n_1 = n_2;
		n_2 = temp;
	}
	return n_2;
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::cout << nFib(n) << '\n';
	return 0;
}
