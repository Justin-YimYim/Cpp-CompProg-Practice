#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	int f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int N=1e5+10;
int n,m,gar,ans,a[N],b[N];
map<int,int>mp1,mp2;
signed main(){
	read(n),read(gar);
	for(int i=1;i<=n;i++)read(a[i]);
	read(m),read(gar);
	for(int i=1;i<=m;i++)read(b[i]);
	for(int k=2;k<=(int)(2e10);k<<=1){
		mp1.clear(),mp2.clear();
		for(int i=1;i<=n;i++)mp1[a[i]%k]++;
		for(int i=1;i<=m;i++)mp2[b[i]%k]++;
		for(int i=1;i<=n;i++)
			ans=max(ans,mp1[a[i]%k]+mp2[(a[i]+k/2)%k]);
		for(int i=1;i<=m;i++)
			ans=max(ans,mp1[(b[i]+k/2)%k]+mp2[b[i]%k]);
	}
	cout<<ans<<endl;
	return 0;
}