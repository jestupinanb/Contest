#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ld  long double

bool cmp(std::vector<double>& a, std::vector<double>& b) {
	return a[2] >= b[2];
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n, w;
	std::cin >> n >> w;
	std::vector<std::vector<double>> vwr(n, std::vector<double>(3));
	for (int i = 0; i < n; i++)
	{
		std::cin >> vwr[i][0] >> vwr[i][1];
		vwr[i][2] = vwr[i][0] / vwr[i][1];
	}

	sort(vwr.begin(), vwr.end(), cmp);

	ld acum = 0;
	
	for (int i = 0; i < n && w>0; i++)
	{
		ld maxI = std::min((ld)vwr[i][2] * w, (ld)vwr[i][0]);
		ld cant = maxI / vwr[i][2];
		w -= cant;
		acum += maxI;
	}

	std::cout.precision(4);
	std::cout << std::fixed << acum << '\n';

	return 0;
}
