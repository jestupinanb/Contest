//https://codeforces.com/gym/272766/problem/A
#include <bits/stdc++.h>

int main()
{
	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++)
	{
		int n;
		std::cin >> n;
		std::vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> p[i];
		}

		bool roundDanceClockwise = true;
		int posI = p[0];
		for (int j = 1; j < n; j++)
		{
			if (((posI + 1) % n) != (p[j]%n)) {
				roundDanceClockwise = false;
				break;
			}
			posI = p[j];
		}
		bool roundDanceCounterClockwise = true;
		posI = p[0];
		for (int j = 1; j < n; j++)
		{
			if (((posI + n - 1) % n) != (p[j]%n)) {
				roundDanceCounterClockwise = false;
				break;
			}
			posI = p[j];
		}
		if (roundDanceClockwise || roundDanceCounterClockwise) {
			std::cout << "YES"<<std::endl;
		}
		else {
			std::cout << "NO"<<'\n';
		}
	}
}
