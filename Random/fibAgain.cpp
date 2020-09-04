#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long 

long long nFibModM(ll n, ll m) {
	if (n <= 1)
		return n;
	std::vector<long long> f;
	f.push_back(0);
	f.push_back(1);
	f.push_back(1);

	long long newMod = 0;

	for (long long i = 3; true; i++)
	{
		f.push_back((f[i - 2] + f[i - 1]) % m);
		if (f[i - 1] == f[0] && f[i] == f[1]) {
			newMod = i-1;
			break;
		}
	}
	long long res = n % newMod;
	return f[res];
}
	
int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	long long n, m;
	std::cin >> n >> m;
	std::cout << nFibModM(n, m) << '\n';
	return 0;
}
