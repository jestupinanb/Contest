#include <iostream>
#include <bits/stdc++.h>

int arr[100000];
int arr2[100000];

int main()
{
	int n,k;
	std::cin >> n;
	std::cin >> k;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = n-2; 0 <= i; i--)
	{
		int min = INT_MAX;
		for (int j = 1; j <= k; j++)
		{
			if (i + j < n) {
				int dif = std::abs(arr[i] - arr[i + j]) + arr2[i + j];
				if (dif < min)
					min = dif;
			}
		}
		arr2[i] = min;
	}
	std::cout << arr2[0] << std::endl;
}
