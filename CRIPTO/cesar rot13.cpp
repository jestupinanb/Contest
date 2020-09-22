#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


//CESAR CRIPTO variables K
int main()
{
	std::freopen("rot13.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	std::string s;

	int k = 13;

	while (std::cin >> s) {
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			std::cout << (char((s[i]+26-k - 'A') % 26 + 'A'));
		}
		std::cout << '\n';
	}
}

