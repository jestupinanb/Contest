//https://codeforces.com/problemset/problem/1324/B
#include <bits/stdc++.h>

int main()
{
	int t;
	bool pal = false;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::map<int, std::vector<int>> map;
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[j];
			map[a[j]].push_back(j);
		}
		bool pal = false;
		for (auto& v : map) {
			if (v.second.size() >= 3) {
				pal = true;
				break;
			}
			if (v.second.size() == 2) {
				if (!(v.second[0] - v.second[1] == 1 || v.second[0] - v.second[1] == -1)) {
					pal = true;
					break;
				}
			}
		}
		std::cout << (pal ? "YES\n" : "NO\n");
	}
}
