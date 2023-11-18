#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	 int f=1;x=0;char ch=getchar();
	 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	 while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	 x*=f;
}
const int N=2e5+10;
int n,m,fa[N],dp[N][2],rtdp[N][2];
vector<int>v[N];
void add(int x,int y){
	v[x].push_back(y);
	v[y].push_back(x);
}
void dfs(int x){
	dp[x][0]=0,dp[x][1]=1;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y<=n||y==fa[x])continue;
		fa[y]=x,dfs(y);
		dp[x][0]+=dp[y][1];
		dp[x][1]+=min(dp[y][0],dp[y][1]);
	}
}
int calc1(){
	rtdp[1][0]=dp[1][0];
	rtdp[1][1]=1e9;
	for(int i=2;i<=n;i++){
		rtdp[i][0]=dp[i][0]+rtdp[i-1][1];
		rtdp[i][1]=dp[i][1]+min(rtdp[i-1][0],rtdp[i-1][1]);
	}
	return rtdp[n][1];
}
int calc2(){
	rtdp[1][0]=1e9;
	rtdp[1][1]=dp[1][1];
	for(int i=2;i<=n;i++){
		rtdp[i][0]=dp[i][0]+rtdp[i-1][1];
		rtdp[i][1]=dp[i][1]+min(rtdp[i-1][0],rtdp[i-1][1]);
	}
	return min(rtdp[n][0],rtdp[n][1]);
}
int main(){
	read(n),read(m);
	for(int i=1,x,y;i<=n+m;i++)
		read(x),read(y),add(x+1,y+1);
	for(int i=1;i<=n;i++)dfs(i);
	cout<<min(calc1(),calc2())<<endl;
	return 0;
}
