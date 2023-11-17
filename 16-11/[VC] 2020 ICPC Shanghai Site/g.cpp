#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,ev,od,ans;
	cin>>n,ev=n/3,od=n-ev;
	ans=ev*(n-1)-ev*(ev-1)/2;
	cout<<ans<<endl; 
	return 0;
}
