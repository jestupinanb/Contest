#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	//freopen("inPair.txt", "r", stdin);
	std::vector<std::vector<int>> E = { {1,2,3,4},{3,4,2,1} };
	std::map<int, int> E_map;
	E_map[1] = 3;
	E_map[2] = 2;
	E_map[3] = 0;
	E_map[4] = 1;
	std::string m = "101100010100101";
	int n = 4;

	if (m.size() % n != 0) {
		int dif = n - (m.size() % n);
		for (int i = 0; i < dif; i++)
			m += '0';
	}

	for (int i = 0; i < m.size(); i++)
	{
		std::vector<char> subs(n);
		for (int j = 1; j < n + 1; j++, i++)
		{
			subs[E_map[j]] = m[i];
		}
		i--;
		for (int i = 0; i < n; i++)
			std::cout << subs[i];
		std::cout << '\n';
	}

	return 0;
}
