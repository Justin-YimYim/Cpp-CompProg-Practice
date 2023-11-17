#include<bits/stdc++.h>
#define db long double
using namespace std;
db bi(db n,db p1,db v1,db p2,db v2){
	db l=p1,r=p2;
	while(l+1e-10<r){
		db mid=(l+r)/2;
		db t1=min((p1+mid)/v1,(mid-p1+mid)/v1);
		db t2=min((p2-mid+n-mid)/v2,(n-p2+n-mid)/v2);
		if(t1>t2)r=mid;
		else l=mid;
	}
	db t1=min((p1+l)/v1,(l-p1+l)/v1);
	db t2=min((p2-l+n-l)/v2,(n-p2+n-l)/v2);
	return max(t1,t2);
}
db calc(db n,db p1,db v1,db p2,db v2){
	db t[20];
	t[0]=(p1+n)/v1,t[1]=(n-p1+n)/v1;
	t[2]=(n-p2+n)/v2,t[3]=(p2+n)/v2;
	t[4]=max(p1/v1,(n-p2+n-p1)/v2);
	t[5]=max(p1/v1,(p2-p1+n-p1)/v2);
	t[6]=max((n-p2)/v2,(p1+p2)/v1);
	t[7]=max((n-p2)/v2,(p2-p1+p2)/v1);
	t[8]=max((n-p1)/v1,p2/v2);
	db ans=bi(n,p1,v1,p2,v2);
	for(int i=0;i<=8;i++)
		ans=min(ans,t[i]);
	return ans;
}
int main(){
	int T;cin>>T;
	while(T--){
		db n,p1,v1,p2,v2;
		cin>>n>>p1>>v1>>p2>>v2;
		if(p1>p2)swap(p1,p2),swap(v1,v2);
		db ans=calc(n,p1,v1,p2,v2);
		printf("%.8Lf\n",ans);
	}
	return 0;
}
