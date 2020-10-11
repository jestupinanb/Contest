#include <bits/stdc++.h>


int castHexa(int a){
	int a_1;
	if(a>='1'&&a<='9')
		a_1 = a-'0';
	else if(a>='a'&&a<='z')
		a_1 = a-'a'+10;
	return a_1;
}

char castToHexa(int a){
	if(a<10)
		return a+'0';
	else
		return a-10+'a';
}

int main(){
	std::string a="a0fafe17";
	std::string b="28aed2a6";
	int sol = 0;
	
	for(int i=0;i<a.size();i++){
		int a_1 = castHexa(a[i]);
		int b_1 = castHexa(b[i]);
		sol = a_1^b_1;
		std::cout<<castToHexa(sol);
	}
}
