#include <bits/stdc++.h>

#include<bits/stdc++.h>
//    I'm Klaus, Nicklaus
using namespace std;
#define ios ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar,val) memset(ar,val,sizeof ar)
int main(){
	//ios;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		if(a[0]+a[1] <= a[n-1]){
			cout<<"1 2 "<<n<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
