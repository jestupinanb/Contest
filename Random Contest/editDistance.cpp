#include <bits/stdc++.h>

int min(int a, int b, int c) {
	return (a > b) ? (b > c) ? c : b : (a > c) ? c : a;
}

int main() {
	std::string a, b;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::vector<std::vector<int>> arr;
		std::cin >> a;
		std::cin >> b;
		arr.clear();
		arr.resize(a.length() + 1, std::vector<int>(b.length() + 1));
		arr[0][0];
		for (int j = 0; j < a.length()+1; j++)
		{
			for (int k = 0; k < b.length()+1; k++)
			{
				if (j == 0) arr[j][k] = k;
				else if (k == 0) arr[j][k] = j;
				else if (a[j-1] == b[k-1]) arr[j][k] = arr[j - 1][k - 1];
				else arr[j][k] = 1 + min(arr[j - 1][k - 1], arr[j - 1][k], arr[j][k - 1]);
			}
		}
		std::cout << arr[a.length()][b.length()] << std::endl;
	}
	return 0;
}
