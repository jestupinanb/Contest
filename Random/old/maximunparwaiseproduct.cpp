#include <bits/stdc++.h>

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}

	/*int n = 2 * 1e5;
	std::vector<int> a(n,n);*/

	int posMax = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) {
			posMax = i;
			max = a[i];
		}
	}

	int posMax2 = 0;
	int max2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max2 && i != posMax) {
			posMax2 = i;
			max2 = a[i];
		}
	}

	std::cout << (long long)a[posMax] * a[posMax2] << '\n';

}
