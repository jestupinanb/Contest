//https://codeforces.com/problemset/problem/1320/A
#include <bits/stdc++.h>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> b(n + 1);
	std::vector<int> cb(n + 1);
	std::map<int, long long> mp;
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		cb[i] = i - b[i];
		mp[cb[i]] += b[i];
	}
	long long max = 0;
	int cbmax = 0;
	for (std::map<int, long long>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > max) {
			max = it->second;
			cbmax = it->first;
		}
	}
	std::cout << max;
}

