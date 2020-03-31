//https://codeforces.com/contest/1332/problem/A
#include <bits/stdc++.h>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c, d;
		long long x, y, x1, y1, x2, y2;
		std::cin >> a >> b >> c >> d;
		std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x2 == x1 && (a > 0 || b > 0)) {
			std::cout << "No" << std::endl;
		}
		else if (y2 == y1 && (c > 0 || d > 0)) {
			std::cout << "No" << std::endl;
		}
		else {
			if (a > b) {
				a = a - b;
				b = 0;
			}
			else
			{
				b = b - a;
				a = 0;
			}
			if (c > d)
			{
				c = c - d;
				d = 0;
			}
			else
			{
				d = d - c;
				c = 0;
			}
			if (x - a<x1 || x + b>x2 || y - c<y1 || y + d>y2) {
				std::cout << "No" << std::endl;
			}
			else {
				std::cout << "Yes" << std::endl;
			}
		}
 
	}
	return 0;
}
