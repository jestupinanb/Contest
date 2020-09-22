#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	std::cin >> n;
	std::vector<int> numOperations(n + 1, INT_MAX);
	std::vector<int> betterOption(n + 1);
	numOperations[1] = 0;
	betterOption[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i + 1 < n + 1) {
				numOperations[i + 1] = std::min(numOperations[i + 1], numOperations[i] + 1);
				if (numOperations[i + 1] == numOperations[i] + 1)
					betterOption[i + 1] = i;
			}
			if (i * 2 < n + 1) {
				numOperations[i * 2] = std::min(numOperations[i * 2], numOperations[i] + 1);
				if (numOperations[i * 2] == numOperations[i] + 1)
					betterOption[i * 2] = i;
			}
			if (i * 3 < n + 1) {
				numOperations[i * 3] = std::min(numOperations[i * 3], numOperations[i] + 1);
				if (numOperations[i * 3] == numOperations[i] + 1) {
					betterOption[i * 3] = i;
				}
			}
		}
	}
	std::list<int> s;
	std::cout << numOperations[n] << '\n';
	for (int i = n; i != 1; i = betterOption[i]) {
		s.push_back(i);
	}
	s.push_back(1);

	while (!s.empty()) {
		std::cout << s.back() << ' ';
		s.pop_back();
	}

	return 0;
}
