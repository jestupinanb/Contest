#include <bits/stdc++.h>

int binSearch(int a, int b) {
	std::string s;
	if (a == b) {
		return a;
	}
	int m = (b + a) / 2;
	if (m == b) {
		std::cout << b + 1;
		std::cin >> s;
		if (s.size() == 1)
			return b;
		else
			return b + 1;
	}
	std::cout << m << std::endl;
	std::cin >> s;
	if (s.size() == 1) {
		binSearch(a, m - 1);
	}
	else {
		binSearch(m + 1, b);
	}
}

int main()
{
	//fflush(stdout);
	int n;
	std::cin >> n;
	std::cout << (binSearch(1, n));
}
