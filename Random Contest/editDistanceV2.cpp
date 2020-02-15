#include <bits/stdc++.h>

std::vector<std::vector<int>> arr;

int min(int a,int b,int c) {
	return (a > b) ? (b > c) ? c : b : (a>c) ? c: a;
}

int editDist(std::string a, std::string b, int al,int bl) {
	if (al == 0) return bl;
	if (bl == 0) return al;
	if (arr[al - 1][bl - 1] != 0) return arr[al - 1][bl - 1];

	if (a[al-1] == b[bl-1]) {
		arr[al - 1][bl - 1] = editDist(a, b, al - 1, bl - 1);
		return arr[al - 1][bl - 1];
	}
	arr[al - 1][bl - 1] = 1 + min(editDist(a, b, al - 1, bl - 1), editDist(a, b, al - 1, bl), editDist(a, b, al, bl - 1));
	return arr[al - 1][bl - 1];
}

int main() {
	std::string a, b;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		std::cin >> b;
		arr.clear();
		arr.resize(a.length(), std::vector<int>(b.length()));
		std::cout<<editDist(a, b, a.length(), b.length())<<std::endl;
	}
	return 0;
}
