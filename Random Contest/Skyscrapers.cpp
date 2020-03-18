//https://codeforces.com/problemset/problem/1313/C1
#include <bits/stdc++.h>

std::tuple<std::vector<int>,long long> floors(std::vector<int> m, int left, int right) {
	int min = INT_MAX;
	int pMin = INT_MAX;
	if (left == right) {
		return std::make_tuple(m,0);
	}
	for (int i = left; i < right; i++)
	{
		if (min > m[i]) {
			min = m[i];
			pMin = i;
		}
	}
	std::vector<int> mr = m;
	long long sumRight = 0;
	for (int i = pMin; i < right; i++)
	{
		if (m[i] > min) {
			sumRight += min;
			mr[i] = min;
		}
		else {
			sumRight += m[i];
		}
	}
	std::vector<int> ml = m;
	long long sumLeft = 0;
	for (int i = left; i <= pMin; i++)
	{
		if (m[i] > min) {
			sumLeft += min;
			ml[i] = min;
		}
		else {
			sumLeft += m[i];
		}
	}
	std::tuple<std::vector<int>, long long> l = floors(ml, pMin + 1, right);
	std::get<1>(l) += sumLeft;
	std::tuple<std::vector<int>, long long> r = floors(mr, left, pMin);
	std::get<1>(r) += sumRight;
	return std::get<1>(l) > std::get<1>(r) ? l : r;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> m(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> m[i];
	}
	std::vector<int> sol;
	std::tie(sol,std::ignore) = floors(m, 0, n);
	for (int i = 0; i < sol.size(); i++)
	{
		std::cout << sol[i] << " ";
	}
}
