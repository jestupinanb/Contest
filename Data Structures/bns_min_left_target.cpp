#include <bits/stdc++.h>
//pos of value less than the first value for
//shifted array eg 12345 -> 34512 should be 3
int bns_min_left(std::vector<int>& v) {
	int l, r;
	l = 0; r = v.size()-1;
	int left = v[0];
    int target = v.size();
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (v[m] >= left) l = m + 1;
		else{
            target = m;
            r = m-1;
        }
	}
	return target;
}

int main(){
	std::vector<int> v = {4,5,6,7,1,2,3};
	std::cout<<bns_min_left(v)<<'\n';
	return 0;
}
