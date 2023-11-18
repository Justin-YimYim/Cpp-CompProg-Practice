#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		bool flag=0;
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				int y=x/i;
				if(i*2>=y){
					flag=1;
					break;
				}
			}
		}
		printf("%d\n",(int)flag);
	}
	return 0;
} 
