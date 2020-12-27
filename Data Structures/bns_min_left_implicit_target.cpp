#include <bits/stdc++.h>
//pos of value less than the first value for
//shifted array eg 12345 -> 34512 should be 3
int bns_min_left(std::vector<int>& v) {
	int l, r;
	l = 0; r = v.size()-1;
	int left = v[0];
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (v[m] >= left) l = m + 1;
		else r = m;
		if(l==r && v[m]<left) break;
	}
	return l;
}

int main(){
	std::vector<int> v = {4,5,6,7,1,2,3};
	std::cout<<bns_min_left(v)<<'\n';
	v = {1,2,3,4,5,6,7};//eq 7 bc there are no min than the first val
	std::cout<<bns_min_left(v)<<'\n';
	return 0;
}
