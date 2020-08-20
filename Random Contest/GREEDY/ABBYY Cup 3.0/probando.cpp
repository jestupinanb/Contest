#include <bits/stdc++.h>

int main(){
	unsigned int v; // compute the next highest power of 2 of 32-bit v
	v = 1000;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	v |= v >> 64;
	v++;
	std::cout<<v;
}
