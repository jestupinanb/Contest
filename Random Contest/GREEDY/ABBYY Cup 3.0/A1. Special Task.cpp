#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	std::string s;
	std::cin >> s;
	int n = s.size();
	bool firstLetter = (s[0] >= 65 && s[0] <= 74) ? true : false;
	std::vector<bool> letters(10);
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 65 && s[i] <= 74) {
			letters[s[i] - 65] = true;
		}
	}


	int qMark = 0;
	int firstQmark = (s[0] == 63);
	for (int i = 1; i < n; i++)
	{
		qMark += (s[i] == 63);
	}

	int numLetters = firstLetter ? -1 : 0;

	for (int i = 0; i < letters.size(); i++)
	{
		numLetters += letters[i];
	}

	long long result = (firstLetter ? 9 : 1);

	int firstVal = (firstLetter ? 9 : 10);

	//letters
	for (int i = firstVal - numLetters + 1; i <= firstVal; i++)
	{
		result *= i;
	}

	result = firstQmark ? 9 * result : result;

	std::cout << result;

	//question marks
	for (int i = 0; i < qMark; i++)
	{
		std::cout << 0;
	}

}
