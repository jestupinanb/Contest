#include <bits/stdc++.h>

int main(){
	std::pair<int, int> firstCord(10,20);
	std::pair<int,int> copy = firstCord;
	copy.first = 1;
	std::cout<<copy.first<<" "<<firstCord.first;
	std::cout<<copy.second<<" "<<firstCord.second;
}
