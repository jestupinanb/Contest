//https://codeforces.com/problemset/problem/653/A
#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> t[i];
	}
	std::sort(t.begin(), t.end());
	std::string rta = "NO";
	for (int i = 0; i < n - 2; i++)
	{
		int count = 1;
		for (int j = i+1; j < n && count <3; j++)
		{
			if (t[i] + count == t[j]) {
				count++;
			}
		}
		if (count == 3) {
			rta = "YES";
			break;
		}
	}
	std::cout << rta;
	return 0;
};
