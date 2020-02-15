#include <iostream>
#include <bits/stdc++.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	std::string a, b;
	std::cin >> a;
	std::cin >> b;

	std::vector<std::vector<int>> arr(a.length() + 1, std::vector<int>(b.length() + 1));

	for (int i = 0; i < a.length() + 1; i++)
	{
		for (int j = 0; j < b.length() + 1; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
		}
	}

	int i = a.length();
	int j = b.length();
	std::string rta = "";
	while (i>0 && j>0)
	{
		if (a[i-1] == b[j-1]) {
			rta = a[i - 1] + rta;
			i--;
			j--;
		}
		else if (arr[i - 1][j] > arr[i][j-1])
			i--;
		else {
			j--;
		}
	}
	std::cout << rta;
}
