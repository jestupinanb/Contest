//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::string s;
		std::cin >> s;
		std::vector<int> sp;
		int numberOfP = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int digit = s[i] - 48;
			if (digit == numberOfP) {}
			else if (digit > numberOfP) {
				sp.push_back(-1);//open
				sp.push_back(digit - numberOfP);
				numberOfP = digit;
			}
			else {
				sp.push_back(-2);//close
				sp.push_back(numberOfP - digit);
				numberOfP = digit;
			}
			sp.push_back(digit);
		}

		if (numberOfP>0) {
			sp.push_back(-2);//close
			sp.push_back(numberOfP);
		}

		std::cout << "Case #" << i+1 << ": ";
		for (int i = 0; i < sp.size(); i++)
		{
			if (sp[i] >= 0) {
				std::cout << sp[i];
			}
			else if (sp[i] == -1) {
				i++;
				for (int j = 0; j < sp[i]; j++)
				{
					std::cout << "(";
				}
			}
			else {
				i++;
				for (int j = 0; j < sp[i]; j++)
				{
					std::cout << ")";
				}
			}
		}
		std::cout << '\n';
	}
	return 0;
}
