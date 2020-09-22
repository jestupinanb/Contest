#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int majorityElement(int l, int r, std::vector<int>& a) {
	//get left, right count how many times does it apear in leaft an right
	if (l == r)//should be l==r || l<r?
		return a[l];

	int m = (r - l) / 2 + l;
	int majL = majorityElement(l, m, a);
	int majR = majorityElement(m + 1, r, a);

	int countL = 0;
	int countR = 0;
	for (int i = l; i <= r; i++)
	{
		if (a[i] == majL)
			countL++;
		if (a[i] == majR)
			countR++;
	}

	if (countL > (1 + r - l) / 2)
		return majL;
	if (countR > (1 + r - l) / 2)
		return majR;
	return -1;

}

int main()
{
	//std::freopen("in.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}

	std::cout << (majorityElement(0, n - 1, a) == -1 ? 0 : 1);

	return 0;
}
