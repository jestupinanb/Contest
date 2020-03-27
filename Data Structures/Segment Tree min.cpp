#include <bits/stdc++.h>

void build(std::vector<int>& vSegTree, std::vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		vSegTree[n + i] = v[i];
	}

	for (int i = n - 1; i >= 1; i--)
	{
		vSegTree[i] = std::min(vSegTree[2 * i], vSegTree[2 * i + 1]);
	}
}

//find (a,b]
int findMin(std::vector<int> vSegTree, int l, int r, int n) {
	l += n;
	r += n + 1;
	int min = INT_MAX;
	while (l < r) {
		if (l & 1) {
			min = std::min(min, vSegTree[l]);
			l++;
		}
		if (r & 1) {
			r--;
			min = std::min(min, vSegTree[r]);
		}
		l /= 2;
		r /= 2;
	}
	return min;
};

int main()
{
	std::vector<int> v = { -1,-2,-3,-4,-5,-6 };
	std::vector<int> vSegTree(2 * v.size());
	build(vSegTree, v);
	std::cout << findMin(vSegTree,0,2,v.size());
	std::cout << "helo";
}
