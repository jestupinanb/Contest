#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int oo = 1e9;

int n, k;
const int nx = 1e5+5;
ll ac[nx][2];
ll dp[105][nx];
ll go(ll i, ll w){
	if(w>k) return -oo;
	if(i == n) return 0;
	if(dp[i][w] != -1) return dp[i][w];
	ll& ans = dp[i][w];
	ans = max(ans, go(i+1,w));
	if(w+ac[i][0]<=k) ans = max(ans, go(i+1,w+ac[i][0])+ac[i][1]);
	return ans;
}
int main(){
	
	cin>>n>>k;
	memset(dp, -1, sizeof dp);
	for(int i=0; i<n; i++) cin>>ac[i][0]>>ac[i][1];
	cout<<go(0,0)<<"\n";
}
