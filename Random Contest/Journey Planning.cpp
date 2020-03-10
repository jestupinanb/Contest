//https://codeforces.com/problemset/problem/1320/A
#include <bits/stdc++.h>
#include <vector>

std::vector<std::vector<int>> dp;

long long lcs(std::vector<int> b, int t, int i, int n) {
    long long max = 0;
    if (i == n) return 0;
    if(dp[t][i] != -1) return dp[t][i];
    if (t == n){
        dp[t][i] = std::max(lcs(b, t, i + 1, n), b[i] + lcs(b, i, i + 1, n));
        return dp[t][i];
    }
    if (i - t  == b[i] - b[t])
        max = b[i]+lcs(b, i, i + 1, n);
    long long temp = lcs(b, t, i + 1, n);
    if (temp > max) max = temp;
    dp[t][i] = max;
    return max;
}

int main()
{
    int n;
    std::cin >> n;
    dp.resize(n+1,std::vector<int>(n,-1));
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << lcs(b, n, 0, n);
}
