//https://practice.geeksforgeeks.org/problems/painting-the-fence/0
#include <bits/stdc++.h>

int MOD_VAL = 1e9 + 7;

/*
std::pair<long long, long long> paintingFence(int n, int k) {
	if (n == 1)
		return std::pair<long long, long long>(0, k);
	std::pair<long long, long long> sol = paintingFence(n - 1, k);
	return std::pair<long long, long long>(sol.second, ((k - 1) * (sol.first + sol.second) % MOD_VAL) % MOD_VAL);
}
*/

int main()
{
	int t;	
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long n, k;
		std::cin >> n >> k;

		//std::pair<long long, long long> sol = paintingFence(n, k);
		//long long total = sol.first + sol.second;

		long long e = 0;
		long long d = k;
		long long total = d + e;
		for (int i = 2; i <= n; i++)
		{
			long long eTemp = d;
			long long dTemp = ((k - 1) * (e + d) % MOD_VAL) % MOD_VAL;
			e = eTemp;
			d = dTemp;
			total = (e + d)%MOD_VAL;
		}
		std::cout << total << std::endl;
	}
}
