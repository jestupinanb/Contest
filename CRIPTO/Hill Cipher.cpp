#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(a % b,a);
}


//Ya dada la matriz inversa
int main()
{
	//std::freopen("rot13.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	std::string s;
	std::cin >> s;
	s += (s.size() % 2) ? "x" : "";
	for (int i = 0; i < s.size(); i+=2)
	{
		int a1 = s[i]-'A';
		int a2 = s[i + 1]-'A';
		int val = (a1 * 7 + a2 * 23) % 26;
		std::cout << char((val) + 'A');
		std::cout<< char(((a1 * 18 + a2 * 11) % 26)+'A');
	}
	std::cout << '\n';
	for (int i = 0; i < s.size(); i += 2)
	{
		int a1 = s[i] - 'A';
		int a2 = s[i + 1] - 'A';
		int val = (a1 * 7 + a2 * 23) % 26;
		std::cout << val<<" ";
		int val2 = (a1 * 18 + a2 * 11) % 26;
		std::cout << val2 << '\n';
	}
	return 0;
}
