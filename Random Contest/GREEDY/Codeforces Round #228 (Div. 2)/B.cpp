#include <bits/stdc++.h>

bool cross(int i, int j, int nrow, int ncol, std::vector<std::string>& v) {
	if (i + 1 >= nrow || i + 2 >= nrow || j - 1 < 0 || j + 1 >= ncol)
		return false;
	if (v[i][j] != '#' || v[i + 1][j - 1] != '#' || v[i + 1][j] != '#' || v[i + 1][j + 1] != '#' || v[i + 2][j] != '#')
		return false;
	v[i][j] = '.';
	v[i + 1][j - 1] = '.';
	v[i + 1][j] = '.';
	v[i + 1][j + 1] = '.';
	v[i + 2][j] = '.';
	return true;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	bool posible = true;
	for (int i = 0; i < n && posible; i++)
	{
		for (int j = 0; j < n && posible; j++)
		{
			if (v[i][j] == '#') {
				if (!cross(i, j, n, n, v)) {
					posible = false;
				}
			}
		}
	}
	std::cout << (posible ? "YES" : "NO");
}
