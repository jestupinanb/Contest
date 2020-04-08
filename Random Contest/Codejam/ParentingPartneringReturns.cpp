//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
#include <bits/stdc++.h>

bool sort(std::vector<int>& v1, std::vector<int>& v2) {
	return v1[0] < v2[0];
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> se(n, std::vector<int>(3));
		for (int j = 0; j < n; j++)
		{
			std::cin >> se[j][0] >> se[j][1];
			se[j][2] = j;
		}
		std::sort(se.begin(), se.end(), sort);
		bool imposible = false;
		bool cBusy = false;
		int fc = -1;
		bool jBusy = false;
		int fj = -1;
		int time;
		std::vector<char> ans(n);
		for (int i = 0; i < n; i++)
		{
			time = se[i][0];
			if (cBusy && fc <= time) {
				cBusy = false;
			}

			if (jBusy && fj <= time) {
				jBusy = false;
			}

			if (!cBusy) {
				ans[se[i][2]] = 'C';

				cBusy = true;
				fc = se[i][1];
			}
			else if (!jBusy) {
				ans[se[i][2]] = 'J';

				jBusy = true;
				fj = se[i][1];
			}
			else {
				imposible = true;
				break;
			}
		}
		std::cout << "Case #" << i + 1 << ": ";
		if (imposible) {
			std::cout << "IMPOSSIBLE\n";
		}
		else {
			for (int i = 0; i < ans.size(); i++)
			{
				std::cout << ans[i];
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
