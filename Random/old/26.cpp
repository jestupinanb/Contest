#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

long long nFib(long long n) {
	if (n <= 1)
		return n;
	long long n_1 = 0;
	long long n_2 = 1;
	std::vector<int> fsum;
	fsum.push_back(0);
	fsum.push_back(1);
	for (int i = 2; i <= 61; i++)
	{
		long long temp = n_1 + n_2;
		n_1 = n_2;
		n_2 = temp;
		fsum.push_back((fsum[i - 1] + n_2) % 10);
		if (fsum[i] == fsum[1] && fsum[i - 1] == fsum[0]) {
			break;
		}
	}
	return fsum[n % 60];
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	long long n;
	std::cin >> n;
	std::cout << nFib(n) << '\n';
	return 0;
}
