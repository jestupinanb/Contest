//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	for (int iSup = 0; iSup < t; iSup++)
	{
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> m(n, std::vector<int>(n));
		std::vector<std::vector<int>> countRow(n, std::vector<int>(n + 1));
		std::vector<std::vector<int>> countCol(n, std::vector<int>(n + 1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cin >> m[i][j];
				countRow[i][m[i][j]] += 1;
				countCol[j][m[i][j]] += 1;
			}
		}

		int r = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (countRow[i][j] > 1) {
					r++;
					break;
				}
			}
		}

		int c = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (countCol[i][j] > 1) {
					c++;
					break;
				}
			}
		}

		int k = 0;
		for (int i = 0; i < n; i++)
		{
			k += m[i][i];
		}

		std::cout << "Case #" << iSup + 1 << ": " << k << " " << r << " " << c << std::endl;
	}
	return 0;
}
