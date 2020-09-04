#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int a, b;
	std::cin >> a >> b;
	std::cout << (long long)a*b/gcd(a, b) << '\n';
	return 0;
}
