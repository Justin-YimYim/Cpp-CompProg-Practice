#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	 int f=1;x=0;char ch=getchar();
	 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	 while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	 x*=f;
}
const int N=2e5+10;
int n,d,c;
vector<int>ans[N];
void failed(){puts("No"),exit(0);}
void add_edge(int i,int j){
	ans[i].push_back(j);
	ans[j].push_back(i);
}
void calc(int l,int r){
	if(r-l+1<=d)failed();
	if((r-l+1&1)&&(d&1))failed();
	if(d*(r-l+1)/2<(r-l+1)-1)failed();
	for(int ind=1;2*ind<=d;ind++)
		for(int i=l;i<=r;i++)
			add_edge(i,(i+ind-l)%(r-l+1)+l);
	if(d&1){
		int hf=(r-l+1)/2;
		for(int i=l;i<l+hf;i++)
			add_edge(i,i+hf);
	}
}
int main(){
	cin>>n>>d>>c;
	if(d==0&&c!=n)failed();
	int s=n/c;
	if((d&1)&&(s&1))s--;
	for(int i=1;i<c;i++)
		calc(s*(i-1)+1,s*i);
	calc(s*(c-1)+1,n);
	puts("Yes");
	for(int i=1;i<=n;i++){
		sort(ans[i].begin(),ans[i].end());
		for(int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
