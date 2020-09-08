#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	long  long m;
	std::cin >> m;
	long long num10 = m/10;
	m %= 10;
	int num5 = m / 5;
	m %= 5;
	std::cout << num10 + num5 + m << '\n';
	return 0;
}
