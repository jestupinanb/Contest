//https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/A
#include <bits/stdc++.h>

bool trips(int o, int i, std::vector<bool>& I, std::vector<bool>& O, std::vector<std::vector<int>> P) {
	if (P[o][i] != -1) {
		return P[o][i];
	}
	if (o == i) {
		P[o][i] = true;
		return P[o][i];
	}
	if (std::abs(o - i) == 1) {
		if (O[o] && I[i]) {
			P[o][i] = true;
			return P[o][i];
		}
		else {
			P[o][i] = false;
			return P[o][i];
		}
	}
	int val;
	if (o < i) {
		// o se acerca 1
		val = 1;
	}
	else {
		//o>i
		val = -1;
	}
	int new_i = o + val;
	if (O[o] && I[new_i]) {
		P[o][i] = trips(new_i, i, I, O, P);
		return P[o][i];
	}
	else {
		P[o][i] = false;
		return P[o][i];
	}
}

int main()
{
	std::ofstream file("output.txt");
	std::ifstream fileI("input.txt");
	int t;
	fileI >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		fileI >> n;
		std::vector<bool> I(n);
		for (int j = 0; j < n; j++)
		{
			char val;
			fileI >> val;
			if (val == 'N') {
				I[j] = false;
			}
			else
			{
				I[j] = true;
			}
		}
		std::vector<bool> O(n);
		for (int j = 0; j < n; j++)
		{
			char val;
			fileI >> val;
			if (val == 'N') {
				O[j] = false;
			}
			else
			{
				O[j] = true;
			}
		}

		std::vector<std::vector<int>> P(n, std::vector<int>(n, -1));

		//OUTPUT
		file << "Case #" << i + 1 << ": " << std::endl;

		for (int o = 0; o < n; o++)
		{
			for (int i = 0; i < n; i++)
			{
				file << (trips(o, i, I, O, P) ? "Y" : "N");
			}
			file << std::endl;
		}
	}
	file.close();
}
