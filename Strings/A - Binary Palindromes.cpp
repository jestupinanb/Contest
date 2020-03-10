#include <bits/stdc++.h>

std::vector<std::vector<int>> arrDp;

int main() {
	int q, n;
	std::cin >> q;
	for (int i = 0; i < q; i++)
	{
		int ones = 0;
		int zeros = 0;
		int even = 0;
		int odd = 0;
		std::cin >> n;
		char si;
		std::cin.get(si);
		for (int j = 0; j < n; j++)
		{
			int length = 0;
			while (std::cin.get(si) && si != '\n') {
				if (si == '0') zeros++;
				if (si == '1') ones++;
				length++;
			}
			if (length % 2)
				odd++;
			else even++;
		}

		if (odd) {
			int tempOnes = ones;
			int tempZeros = zeros;
			for (int i = 0; i < odd; i++)
			{
				if (tempOnes > 0 && tempOnes % 2) 
					tempOnes--;
				else if (tempZeros > 0 && tempZeros % 2) 
					tempZeros--;
				else if (tempOnes > 0) 
					tempOnes--;
				else 
					tempZeros--;
			}
			if (tempOnes % 2 == 0 && tempZeros % 2 == 0) std::cout << odd + even;
			else std::cout << odd + even - 1;
		}
		else {
			if (ones % 2 == 0 && zeros % 2 == 0) std::cout << odd + even;
			else std::cout << odd + even - 1;
		}
		std::cout << '\n';
	}
	return 0;
};
