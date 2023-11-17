#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int q[40][2][2],mx1,mx2;
int get_max(int num){
	for(int i=35;i>=0;i--){
		if(num&(1ll<<i))return i+1; 
	}
	return 0;
}
int solve(int x,int y){
	int ans=0;
	for(int i=1;i<=36;i++){
		if(i>mx2)break;
//		cout<<i<<' '<<ans<<endl;
		q[i][0][0]=q[i-1][0][0]*3+2;
		if(x&((int)1<<i-1))q[i][1][0]=2*q[i-1][0][0]+q[i-1][1][0]+2;
		else q[i][1][0]=2*q[i-1][1][0]+1;
		if(y&((int)1<<i-1))q[i][0][1]=2*q[i-1][0][0]+q[i-1][0][1]+2;
		else q[i][0][1]=2*q[i-1][0][1]+1;
		if((x&((int)1<<i-1))&&(y&((int)1<<i-1))){
			q[i][1][1]=q[i-1][1][0]+q[i-1][0][1]+q[i-1][0][0]+2;
//			ans+=(q[i-1][1][0]+q[i-1][0][1]+2)*i;
		}
		else if(x&((int)1<<i-1)){
			q[i][1][1]=q[i-1][1][1]+q[i-1][0][1]+1;
//			ans+=(q[i-1][1][1]+1)*i;
		}
		else if(y&((int)1<<i-1)){
			q[i][1][1]=q[i-1][1][1]+q[i-1][1][0]+1;
//			ans+=(q[i-1][1][1]+1)*i;
		}
		else q[i][1][1]=q[i-1][1][1];
		if(i<mx1)ans+=(q[i-1][0][0]*2+2)*i;
		else if(i==mx1){
			if(i!=mx2)ans+=(q[i-1][1][0]+q[i-1][0][0]+2)*i;
			else ans+=(q[i-1][1][0]+q[i-1][0][1]+2)*i;
		}
		else if(i<mx2)ans+=(q[i-1][1][0]+1)*i;
		else ans+=(q[i-1][1][1]+1)*i;
//		if(i==mx1&&i==mx2)ans+=(q[i-1][1][0]+q[i-1][0][1]+2)*i;
//		else if(i<=mx1){
//			if(i==mx1)
//			el
//		}
//		else if(i>=mx2){if(i==mx2)ans+=(q[i-1][0][1]+q[i-1][0][0]+2)*i;}
//		else 
		q[i][0][0]%=mod;
		q[i][1][0]%=mod;
		q[i][0][1]%=mod;
		q[i][1][1]%=mod;
		ans%=mod;
	}
	return ans;
}
signed main(){
//	freopen("data.in","r",stdin);
//	freopen("TC.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(x>y)swap(x,y);
		mx1=get_max(x);
		mx2=get_max(y);
		printf("%lld\n",solve(x,y));
	}
	return 0;
}
