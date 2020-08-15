//https://codeforces.com/contest/1395/problem/B
#include <bits/stdc++.h>

int main()
{
	int n, m, sx, sy;
	std::cin >> n >> m >> sx >> sy;
	sx -= 1;
	sy -= 1;
	int y = sy;
	for (int i = 0; i < n; i++)
	{
		int x = (sx+i) % n;
		sy = y;
		for (int j = 0; j < m; j++)
		{
			y = (sy + j) % m;
			std::cout<<x+1<<" "<<y+1<<std::endl;
		}
	}
}
