//https://www.geeksforgeeks.org/game-theory-choice-area/
#include <bits/stdc++.h>

int max(int a, int b, int c){
	return std::max(a, std::max(b, c));
}

int maxTime(int a, int b, std::vector<int>& x, std::vector<int>& y, std::vector<int>& z,char chosen, std::vector<std::vector<std::vector<int>>>& dp) {
	if (a < 0 || b < 0)
		return -1;
	int xVal, yVal, zVal;
	xVal = INT_MIN;
	yVal = INT_MIN;
	zVal = INT_MIN;
	if (dp[a][b][chosen - 119] != -1)
		return dp[a][b][chosen - 119];
	if (chosen != 'x')
		xVal = maxTime(a + x[0], b + x[1], x, y, z,'x',dp);
	if (chosen != 'y')
		yVal = maxTime(a + y[0], b + y[1], x, y, z,'y',dp);
	if (chosen != 'z')
		zVal = maxTime(a + z[0], b + z[1], x, y, z,'z',dp);
	dp[a][b][chosen - 119] = 1 + max(xVal, yVal, zVal);
	return dp[a][b][chosen - 119];
}

int main()
{
	int a;
	std::cin >> a;
	int b;
	std::cin >> b;
	std::vector<int> x(2);
	std::cin >> x[0] >> x[1];
	std::vector<int> y(2);
	std::cin >> y[0] >> y[1];
	std::vector<int> z(2);
	std::cin >> z[0] >> z[1];
	std::vector<std::vector<std::vector<int>>> dp(a+100, std::vector<std::vector<int>>(b+100, std::vector<int>(4, -1)));
	std::cout<<maxTime(a, b, x, y, z, 'w',dp);
}
