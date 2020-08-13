//https://practice.geeksforgeeks.org/problems/max-length-chain/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

int maxLengthChain(int pair, int i, struct val v[], int vSize,std::vector<std::vector<int>>& dp) {
	if (i == vSize) {
		return 0;
	}
	if (dp[pair][i] != -1)
		return dp[pair][i];
	if (pair == vSize || v[pair].first > v[i].second) {
		return dp[pair][i] = std::max(1 + maxLengthChain(i, 0, v, vSize,dp), maxLengthChain(pair, i + 1, v, vSize,dp));
	}
	else {
		return dp[pair][i] = maxLengthChain(pair, i + 1, v, vSize,dp);
	}
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n,-1));
	return  maxLengthChain(n, 0, p, n,dp);
}
