#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	std::string s;
	std::cin >> s;
	int n = s.size();
	long long result = 1;
	std::vector<bool> letters('J' - 'A' + 1);
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'J')
			letters[s[i] - 'A'] = true;
	}

	int valToMult = 10;
	for (int i = 0; i < letters.size(); i++)
	{
		if (letters[i]) {
			if (valToMult == 10 && s[0] >= 'A' && s[0] <= 'J') {
				result *= 9;
			}
			else {
				result *= valToMult;
			}
			valToMult--;
		}
	}

	if (s[0] == '?')
		result *= 9;

	std::cout << result;

	for (int i = 1; i < n; i++)
	{
		if (s[i] == '?')
			std::cout << 0;
	}
}

