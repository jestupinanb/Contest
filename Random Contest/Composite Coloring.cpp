//https://codeforces.com/contest/1332/problem/A
#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	std::vector<int> rta(1000 + 1);
	int color = 0;
	for (int i = 2; i <= 1000; i++)
	{
		if (rta[i] == 0) {
			color++;
			for (int j = 1; j <= 1000 && j * i <= 1000; j++)
			{
				if (rta[i * j] == 0) {
					rta[i * j] = color;
				}
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::map<int, int> mp;
		std::vector<int> rtaFinal;
		int count = 1;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a[i];
			if (mp[rta[a[i]]] == 0) {
				mp[rta[a[i]]] = count;
				count++;
			}
			rtaFinal.push_back(rta[a[i]]);
		}
		std::cout << mp.size() << std::endl;
		for (auto& v : rtaFinal)
		{
			std::cout << mp[v] << " ";
		}
		std::cout << '\n';
	}
	return 0;
}
