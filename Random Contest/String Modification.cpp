//https://codeforces.com/problemset/problem/1316/B
#include <bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::string s;
		std::cin >> n >> s;
		std::vector<std::string> t(n);
		t[0] = s;
		for (int k = 2; k <= n; k++)
		{
			std::string fHalf = s.substr(k - 1, n - (k - 1));
			std::string sHalf = s.substr(0, k - 1);
			if (k % 2 == n % 2) {
				std::reverse(sHalf.begin(), sHalf.end());
			}
			t[k - 1] = fHalf + sHalf;
		}
		std::string minsk = t[0];
		int mink = 1;
		for (int i = 0; i < t.size(); i++)
		{
			std::string v = t[i];
			if (minsk.compare(v) > 0) {
				minsk = v;
				mink = i + 1;
			}
		}
		std::cout << minsk << std::endl << mink << std::endl;
	}
	return 0;
}

/*
//codigo usado para identificar el patron

std::string s = "abc";
int n = s.size();
std::cout << n<<'\n';
for (int k = 1; k <= n; k++)
{
	std::string stemp = s;
	for (int i = 0; i < n-k+1; i++)
	{
		int subN = i + k - 1;
		for (int j = i; j < i+k/2; j++)
		{
			std::swap(stemp[j], stemp[subN-j+i]);
		}
	}
	std::cout << k << " " << stemp<<'\n';
}
std::cout << "--------- \n";
s = "abcd";
n = s.size();
std::cout << n << '\n';
for (int k = 1; k <= n; k++)
{
	std::string stemp = s;
	for (int i = 0; i < n - k + 1; i++)
	{
		int subN = i + k - 1;
		for (int j = i; j < i + k / 2; j++)
		{
			std::swap(stemp[j], stemp[subN - j + i]);
		}
	}
	std::cout << k << " " << stemp << '\n';
}
std::cout << "--------- \n";
std::cout << "New algo \n";
s = "abc";
n = s.size();
std::cout << n << '\n';
*/
