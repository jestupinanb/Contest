//https://practice.geeksforgeeks.org/problems/repetitive-addition-of-digits/0
#include <bits/stdc++.h>

std::string repetitiveAdditionsDigits(std::string n) {
	if (n.length() == 1)
		return n;
	int sum = 0;
	for (int i = 0; i < n.length(); i++)
	{
		sum += n[i] - 48;
	}
	return repetitiveAdditionsDigits(std::to_string(sum));
}

int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::string n;
		std::cin >> n;
		std::cout << repetitiveAdditionsDigits(n)<<std::endl;
	}
}
