#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	//freopen("inPair.txt", "r", stdin);
	//std::vector<std::vector<int>> E = { {1,2,3,4},{3,4,2,1} };
	std::map<int, int> E_map;
	E_map[1] = 4-1;
	E_map[2] = 1-1;
	E_map[3] = 2-1;
	E_map[4] = 3-1;
	std::string m = "101100010100101";
	std::string c0_iv = "1010";
	int n = 4;

	if (m.size() % n != 0) {
		int dif = n - (m.size() % n);
		for (int i = 0; i < dif; i++)
			m += '0';
	}

	for (int i = 0; i < m.size(); i++)
	{
		std::vector<bool> subs(n);
		std::string c_i;
		for (int j = 1; j < n + 1; j++, i++)
		{
			bool m1i = m[i] - '0';
			bool c0i = c0_iv[j-1] - '0';
			subs[E_map[j]] = m1i ^ c0i;
		}
		i--;
		for (int i = 0; i < n; i++) {
			std::cout << subs[i];
			c_i += char(subs[i] + 48);
		}
		c0_iv = c_i;
		std::cout << '\n';
	}

	return 0;
}
