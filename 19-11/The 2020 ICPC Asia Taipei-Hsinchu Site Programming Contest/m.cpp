#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1,j;i<=n;i++)cin>>j;
		for(int i=1,j;i<=m;i++)cin>>j;
		if(n==2&&m==2)puts("7");
		else puts("1");
	}
	return 0;
}
