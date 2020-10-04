#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define LAMBDA "lambda"

int main()
{
	std::unordered_set<int> myset;
	myset.insert(11);
	myset.erase(1);
	std::cout<<(myset.find(1)!=myset.end())<<'\n';
	for(auto& c: myset)
		std::cout<<c<<" ";
}
