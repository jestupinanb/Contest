#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

struct Smt {

	vector<int> vSegTree;
	int n;

	Smt(vector<int>& v) {
		n = v.size();
		vSegTree = vector<int>(2 * v.size());
		build(vSegTree, v);
		//std::cout << findMin(vSegTree, 0, 2, v.size());
	}

	void build(std::vector<int>& vSegTree, std::vector<int>& v) {
		int n = v.size();
		for (int i = 0; i < n; i++) {
			vSegTree[n + i] = v[i];
		}

		for (int i = n - 1; i >= 1; i--) {
			vSegTree[i] = gcd(vSegTree[2 * i], vSegTree[2 * i + 1]);
		}
	}

	//find (a,b]
	int query(int l, int r) {
		l += n;
		r += n + 1;
		int g = -1;
		while (l < r) {
			if (l & 1) {
				if (g == -1) g = vSegTree[l];
				g = gcd(g, vSegTree[l]);
				l++;
			}
			if (r & 1) {
				r--;
				if (g == -1) g = vSegTree[r];
				g = gcd(g, vSegTree[r]);
			}
			l /= 2;
			r /= 2;
		}
		return g;
	};
};
