//https://codeforces.com/problemset/problem/1313/C1
#include <bits/stdc++.h>

std::tuple<int, int> findST(std::vector<std::tuple<int, int>>& vst, int l, int r, int n) {
	l += n;
	r += n;
	std::tuple<int, int> min(INT_MAX, INT_MAX);
	while (l < r)
	{
		if (l & 1) {
			min = std::get<1>(min) > std::get<1>(vst[l]) ? vst[l] : min;
			l++;
		}
		if (r & 1) {
			r--;
			min = std::get<1>(min) > std::get<1>(vst[r]) ? vst[r] : min;
		}
		l /= 2;
		r /= 2;
	}
	return min;
}


std::tuple<std::list<std::tuple<int,bool>>, long long> floors(std::vector<int>& m, std::vector<std::tuple<int, int>>& vst, int left, int right) {
	long long pMin, min;
	std::list<std::tuple<int,bool>> minList;
	std::tie(pMin, min) = findST(vst, left, right, m.size());
	if (left == right) {
		return std::make_tuple(minList, 0);
	}
	long long sumRight = min * (right - pMin);
	long long sumLeft = min * (pMin - left + 1);
	std::tuple<std::list<std::tuple<int,bool>>, long long> l = floors(m, vst, pMin + 1, right);
	std::get<1>(l) += sumLeft;
	std::tuple<std::list<std::tuple<int, bool>>, long long> r = floors(m, vst, left, pMin);
	std::get<1>(r) += sumRight;
	if (std::get<1>(l) > std::get<1>(r)) {
		minList.push_back(std::make_tuple(pMin,0));
		minList.splice(minList.end(), std::get<0>(l));
		return std::make_tuple(minList, std::get<1>(l));
	}
	else {
		minList.push_back(std::make_tuple(pMin,1));
		minList.splice(minList.end(), std::get<0>(r));
		return std::make_tuple(minList, std::get<1>(r));
	}
}

long long floorsN(std::vector<int>& m, std::vector<std::tuple<int, int>>& vst, int left, int right) {
	long long pMin, min;
	//std::list<std::tuple<int, bool>> minList;
	std::tie(pMin, min) = findST(vst, left, right, m.size());
	if (left == right) {
		return 0;
	}
	long long sumRight = min * (right - pMin);
	long long sumLeft = min * (pMin - left + 1);
	long long l = floorsN(m, vst, pMin + 1, right);
	l += sumLeft;
	long long r = floorsN(m, vst, left, pMin);
	r += sumRight;
	if (l > r) {
		return l;
	}
	else {
		return r;
	}
}

void buildST(std::vector<int>& v, std::vector<std::tuple<int, int>>& vst) {
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		vst[i + n] = std::make_tuple(i, v[i]);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		vst[i] = std::get<1>(vst[2 * i]) > std::get<1>(vst[2 * i + 1]) ? vst[2 * i + 1] : vst[2 * i];
	}
}

int main()
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int n;
	std::cin >> n;
	std::vector<int> m(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> m[i];
	}
	std::vector<std::tuple<int, int>> vst(2 * n);
	buildST(m, vst);
	std::list<std::tuple<int,bool>> sol;
	std::cout<< floorsN(m, vst, 0, n);
}
