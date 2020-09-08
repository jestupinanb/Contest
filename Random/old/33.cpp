#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int d, m, n;
	std::cin >> d >> m >> n;
	std::vector<int> stop(n + 1);
	for (int i = 0; i < n; i++)
	{
		std::cin >> stop[i];
	}

	stop[n] = d;

	int countRefill = 0;
	int lastRefill = 0;//distance
	int posible = -1;

	for (int i = 0; i < n + 1; i++)
	{
		if (stop[i] <= lastRefill + m) {
			posible = stop[i];
		}
		else {
			if (posible == -1) {
				lastRefill = -1;
				countRefill = -1;
				break;
			}
			countRefill++;
			lastRefill = posible;
			posible = -1;
			i--;
		}
	}

	std::cout << countRefill << '\n';

	return 0;
}
