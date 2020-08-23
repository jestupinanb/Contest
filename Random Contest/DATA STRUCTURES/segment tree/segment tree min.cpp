#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

void build(int v, int tl, int tr, std::vector<int>& original, std::vector<long long>& segmentTree) {
	if (tl == tr) {
		segmentTree[v] = original[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(2 * v, tl, tm, original, segmentTree);
		build(2 * v + 1, tm + 1, tr, original, segmentTree);
		segmentTree[v] = std::min(segmentTree[2 * v], segmentTree[2 * v + 1]);
	}
}

long long getMinSegment(int left, int right, std::vector<long long>& segmentTree) {
	left += segmentTree.size() / 2;
	right += segmentTree.size() / 2;
	long long min = INT_MAX;
	while (left <= right) {
		if (left % 2 == 1) min = std::min(min,segmentTree[left++]);
		if (right % 2 == 0) min = std::min(min,segmentTree[right--]);
		left /= 2;
		right /= 2;
	}
	return min;
}

void changeValue(int position, int value, std::vector<long long>& segmentTree) {
	position += segmentTree.size() / 2;
	segmentTree[position] = value;
	position /= 2;
	while (position > 0) {
		segmentTree[position] = std::min(segmentTree[2 * position], segmentTree[2 * position + 1]);
		position /= 2;
	}
}

int nextPower2(int a) {
	int next = 1;
	while (next < a) {
		next *= 2;
	}
	return next;
}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	int n, m;
	std::cin >> n >> m;

	std::vector<int> v(nextPower2(n));

	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	std::vector<long long> segmentTree(v.size() * 2);

	build(1, 0, v.size() - 1, v, segmentTree);

	for (int i = 0; i < m; i++)
	{
		int option;
		std::cin >> option;
		if (option == 1) {
			int i, v;
			std::cin >> i >> v;
			changeValue(i, v, segmentTree);
		}
		else {
			int l, r;
			std::cin >> l >> r;
			std::cout<<getMinSegment(l, r - 1,segmentTree)<<std::endl;
		}
	}
}
