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
		segmentTree[v] = segmentTree[2 * v] + segmentTree[2 * v + 1];
	}
}

long long sumSegment(int left, int right, std::vector<long long>& segmentTree) {
	left += segmentTree.size() / 2;
	right += segmentTree.size() / 2;
	long long sum = 0;
	while (left <= right) {
		if (left % 2 == 1) sum += segmentTree[left++];
		if (right % 2 == 0) sum += segmentTree[right--];
		left /= 2;
		right /= 2;
	}
	return sum;
}

void changeValue(int position, int value, std::vector<long long>& segmentTree) {
	position += segmentTree.size() / 2;
	int difference = value - segmentTree[position];
	while (position > 0) {
		segmentTree[position] += difference;
		position /= 2;
	}
}

int nexPowerOf2(int a) {
	int next = 1;
	while (next < a) {
		next *= 2;
	}
	return next;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	//The size of the array should be a power of 2
	v.resize(nexPowerOf2(v.size()));

	//Segment tree size is the size of the original array * 2
	std::vector<long long> segmentTree(v.size() * 2);
	build( 1, 0, v.size() - 1, v, segmentTree);

	//from 0 to n-1(size of v)
	int sum = sumSegment(3, 4, segmentTree);
	std::cout << sum;

	//change value
	changeValue(2, 2, segmentTree);
}

