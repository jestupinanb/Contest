//https://codeforces.com/gym/102307/problem/B
#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;
	if (s[0] >= 48 && s[0] <= 57) {
		std::string s2 = "";
		for (int i = 0; i < s.size() && s[i] >= 48 && s[i] <= 57; i++)
		{
			s2.push_back(s[i]);
		}
		std::cout << s2;
	}
	else {
		std::cout << "-1";
	}
}
