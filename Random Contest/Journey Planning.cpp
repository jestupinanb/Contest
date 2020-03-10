//https://codeforces.com/problemset/problem/1320/A
#include <bits/stdc++.h>
#include <vector>

long long lcs(std::vector<int> b, int t, int i, int n) {
    long long max = 0;
    if (i == n) return 0;
    if (t == -1) return std::max(lcs(b, t, i + 1, n), b[i] + lcs(b, i, i + 1, n));
    if (i - t  == b[i] - b[t])
        max = b[i]+lcs(b, i, i + 1, n);
    long long temp = lcs(b, t, i + 1, n);
    if (temp > max) max = temp;
    return max;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << lcs(b, -1, 0, n);
}
