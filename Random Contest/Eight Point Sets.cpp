//https://codeforces.com/gym/272766/problem/C
#include <bits/stdc++.h>

int main()
{
	std::vector<std::vector<int>> v(8, std::vector<int>(2));
	for (int i = 0; i < 8; i++)
	{
		std::cin >> v[i][0] >> v[i][1];
	}
	std::sort(v.begin(), v.end());
	if (v[0][1] < v[1][1] && v[1][1] < v[2][1] && v[0][0] < v[3][0] && v[3][0] < v[5][0]) {
		bool respectable = true;

		if (!(v[0][0] == v[1][0] && v[1][0] == v[2][0])) {
			respectable = false;
		}
		if (v[3][0] != v[4][0]) {
			respectable = false;
		}
		if (!(v[5][0] == v[6][0] && v[6][0] == v[7][0])) {
			respectable = false;
		}
		if (!(v[0][1] == v[3][1] && v[0][1] == v[5][1] && 
			v[1][1] == v[6][1] &&
			v[2][1] == v[4][1] && v[2][1] == v[7][1]
			)) {
			respectable = false;
		}

		if (respectable)
			std::cout << "respectable";
		else 
			std::cout << "ugly";
	}
	else {
		std::cout << "ugly";
	}
}
