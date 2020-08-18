//https://codeforces.com/problemset/problem/316/A1
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long

int main()
{
	//std::freopen("in2.txt", "r", stdin);
	int c1, c2, c3, c4;
	std::cin >> c1 >> c2 >> c3 >> c4;
	int n, m;
	std::cin >> n >> m;
	std::vector<ll> bus(n);
	std::vector<long long> trolley(m);

	for (int i = 0; i < n; i++)
	{
		std::cin >> bus[i];
	}

	for (int i = 0; i < m; i++)
	{
		std::cin >> trolley[i];
	}

	//total cost with c1
	std::vector<long long> totalTravelBus(n);
	for (int i = 0; i < n; i++)
	{
		totalTravelBus[i] = bus[i] * c1;
	}

	std::vector<long long> totalTravelTrolley(m);
	for (int i = 0; i < m; i++)
	{
		totalTravelTrolley[i] = trolley[i] * c1;
	}

	//is better opticon c2?

	for (int i = 0; i < n; i++)
	{
		totalTravelBus[i] = std::min(totalTravelBus[i], (ll) (c2));
	}

	for (int i = 0; i < m; i++)
	{
		totalTravelTrolley[i] = std::min(totalTravelTrolley[i], (long long)(c2));
	}

	// is better option c3?

		//bus
	long long totalBus = 0;

	for (int i = 0; i < n; i++)
	{
		totalBus += totalTravelBus[i];
	}

	totalBus = std::min(totalBus, (long long)(c3));

		//trolley

	long long totalTrolley = 0;

	for (int i = 0; i < m; i++)
	{
		totalTrolley += totalTravelTrolley[i];
	}

	totalTrolley = std::min(totalTrolley, (long long)(c3));

	//is better option c4? 

	long long totalBusTrolley = totalBus + totalTrolley;

	totalBusTrolley = std::min(totalBusTrolley, (long long)(c4));

	//out
	std::cout << totalBusTrolley;
}

