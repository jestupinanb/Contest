#include <bits/stdc++.h>


void build(std::vector<int>& a, int v, int tl, int tr, std::vector<int>& t) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm, t);
		build(a, v * 2 + 1, tm + 1, tr, t);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

long long sumSegment(std::vector<int>& segmentTree, int left, int right) {
	left += segmentTree.size()/2;
	right += segmentTree.size()/2;
	long long s = 0;
	while (left <= right) {
		if (left % 2 == 1) s += segmentTree[left++];
		if (right % 2 == 0) s += segmentTree[right--];
		left /= 2;
		right /= 2;
	}
	return s;
}

int nexPowerOf2(int a) {
	int nextPower = 1;
	while (nextPower < a) {
		nextPower *= 2;
	}
	return nextPower;
}

void changeValue(int position, int value, std::vector<int>& segmentTree) {
	position += segmentTree.size() / 2;
	int difference = value - segmentTree[position];
	//changing the value in all the parents
	while (position > 0) {
		segmentTree[position] += difference;
		position /= 2;
	}
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	//The size of the array should be a power of 2
	v.resize(nexPowerOf2(v.size()));
	
	//Segment tree size is the size of the original array * 2
	std::vector<int> segmentTree(v.size() * 2);
	build(v, 1, 0, v.size() - 1, segmentTree);

	//from 0 to n-1(size of v)
	int sum = sumSegment(segmentTree, 3, 4);
	std::cout << sum;

	//change value
	changeValue(2, 2, segmentTree);
}

