//https://codeforces.com/gym/102307/problem/B
#include <iostream>

bool isPalindrome(std::string& s,int i,int j) {
	if (i >= j)
		return true;
	return s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : false;
}

int main()
{
	std::string s;
	std::cin >> s;
	int palPos = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isPalindrome(s, i, s.size() - 1)) {
			palPos = i;
			break;
		}
	}
	std::string s2;
	for (int i = palPos-1; i >= 0; i--)
	{
		s2.push_back(s[i]);
	}
	std::cout << s + s2;
}
