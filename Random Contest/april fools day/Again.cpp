//https://codeforces.com/contest/1331/problem/D
#include <bits/stdc++.h>

int main() {
	std::string v;
	std::cin>>v;
	std::cout<<((v[v.size()-1]-48)%2 == 0 ? 0 : 1);
}
