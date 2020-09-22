#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


int min(int a, int b, int c) {
	return std::min(a, std::min(b, c));
}

// i smaller 
int editDistance(int i, int j, std::string& s1, int iSize, std::string& s2, int jSize, std::vector<std::vector<int>>& dp) {
	if (j >= jSize) {
		return iSize - i;
	}
	if (i >= iSize) {
		return jSize - j;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i] == s2[j]) {
		return dp[i][j] = editDistance(i + 1, j + 1, s1, iSize, s2, jSize, dp);
	}
	else {
		return dp[i][j] = 1 + min(editDistance(i + 1, j, s1, iSize, s2, jSize, dp), editDistance(i, j + 1, s1, iSize, s2, jSize, dp), editDistance(i + 1, j + 1, s1, iSize, s2, jSize, dp));
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	std::string s1, s2;
	std::cin >> s1 >> s2;

	std::vector<std::vector<int>> dp(s1.size(), std::vector<int>(s2.size(), -1));
	std::cout << editDistance(0, 0, s1, s1.size(), s2, s2.size(), dp) << std::endl;
	std::cout << "";
	return 0;
}

