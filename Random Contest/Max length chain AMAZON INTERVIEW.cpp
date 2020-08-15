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

//time complexity: O(N*N) 
//Auxiliary Space: O(N)

int maxLengthChain(int pair, int i, struct val v[], int vSize,std::vector<int>& dp) {
	if (i == vSize) {
		return 0;
	}
	if (dp[pair] != -1)
		return dp[pair];
	if (pair == vSize || v[pair].first > v[i].second) {
		if (i == 0)
			return dp[pair] = std::max(1 + maxLengthChain(i, 0, v, vSize, dp), maxLengthChain(pair, i + 1, v, vSize, dp));
		else
			return std::max(1 + maxLengthChain(i, 0, v, vSize, dp), maxLengthChain(pair, i + 1, v, vSize, dp));
	}
	else {
		if (i == 0)
			return dp[pair] = maxLengthChain(pair, i + 1, v, vSize, dp);
		else
			return dp[pair] = maxLengthChain(pair, i + 1, v, vSize, dp);
	}
}

