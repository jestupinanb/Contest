#include <bits/stdc++.h>

int main(){
	std::list<int> l;
	for(int i=0;i<10;i++)
		l.push_back(i+3);
	l.push_back(3);
	for(auto& v:l){
		v+=1;
	}

	l.erase(l.begin()+1);
	
	for(auto const&v :l)
		std::cout<<v<<' ';
	
}
