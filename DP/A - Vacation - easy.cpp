#include <iostream>
#include <limits.h>

int arr[100000][3];

int main()
{
	int n;
	int a, b, c;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}
	for (int i = n-1; 0 <= i; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			int max = INT_MIN;
			for (int k = 0; k < 3; k++)
			{
				if (k!=j) {
					if (arr[i+1][k]>max) {
						max = arr[i + 1][k];
					}
				}
			}
			arr[i][j] += max;
		}
	}
	int max = INT_MIN;
	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i]>max) {
			max = arr[0][i];
		}
	}
	std::cout << max << std::endl;
}
