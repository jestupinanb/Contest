#include<bits/stdc++.h>

int main(){
	std::map<int,int> ma;
	ma[2] = 3;
	ma[3] = 0;
	for(auto &x:ma){
		std::cout<<x.second<<' ';
	}
		
}
