//https://codeforces.com/problemset/problem/1311/C
#include <bits/stdc++.h>
#include <vector>

int main()
{
	#ifdef LOCAL_JUDGE
			freopen("in.txt", "rt", stdin);
		freopen("out.txt", "wt", stdout);
	#endif
	
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		std::cin >> n >> m;
		std::string s;
		std::cin >> s;
		std::vector<int> vm(m);

		std::vector<int> sv(n + 1);
		for (int j = 0; j < m; j++)
		{
			std::cin >> vm[j];
			sv[0]++;
			sv[vm[j]] += -1;
		}
		std::map<char, int> sum;
		int num_lett = 0;
		for (int i = 0; i < n; i++)
		{
			num_lett += sv[i];
			sum[s[i]] += num_lett;
		}
		for (int i = 0; i < s.length(); i++)
		{
			sum[s[i]]++;
		}
		for (char i = 'a'; i <= 'z'; i++)
		{
			std::cout << sum[i] << ' ';
		}
		std::cout << '\n';
	}
}
