#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


int finalPosR(int finalPosPivot, int r, int pivot, std::vector<int>& a) {
	for (finalPosPivot; finalPosPivot <= r && a[finalPosPivot] == pivot; finalPosPivot++)
	{
	}
	return finalPosPivot;
}

int finalPosL(int finalPosPivot, int pivot, std::vector<int>& a) {
	for (finalPosPivot; finalPosPivot >= 0 && a[finalPosPivot] == pivot; finalPosPivot--)
	{
	}
	return finalPosPivot;
}

//improve equal elements
void qSort(int l, int r, std::vector<int>& a,int n) {
	if (l >= r || r>=n || l<=-1)
		return;
	int m = r;
	int pivot = a[m];
	int low = l - 1;
	for (int i = l; i <= r - 1; i++)
	{
		if (pivot > a[i]) {
			low++;
			std::swap(a[low], a[i]);
		}
	}
	int finalPosPivot = low + 1;

	std::swap(a[finalPosPivot], a[m]);

	int lpivot = finalPosL(finalPosPivot, pivot, a);
	for (int i = 0; i < lpivot; i++)
	{
		if (a[i] == pivot) {
			std::swap(a[i], a[lpivot]);
			lpivot = finalPosL(finalPosPivot, pivot, a);
		}
	}

	int rpivot = finalPosR(finalPosPivot, r, pivot, a);
	for (int i = r; i >= rpivot; i--)//>???
	{
		if (a[i] == pivot) {
			std::swap(a[i], a[rpivot]);
			rpivot = finalPosR(finalPosPivot, r, pivot, a);
		}
	}

	lpivot = finalPosL(finalPosPivot, pivot, a);
	rpivot = finalPosR(finalPosPivot, r, pivot, a);

	qSort(l, lpivot, a,n);
	qSort(rpivot, r, a,n);
}

int main()
{
	//std::freopen("in1.txt", "r", stdin);
	//std::freopen("out.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}

	qSort(0, n - 1, a,n);

	for (int i = 0; i < n; i++)
	{
		std::cout << a[i]<<" ";
	}

	return 0;
}
