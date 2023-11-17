#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,cnt;
string A[N],B[N];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<n;i++)cin>>B[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(A[i][j]!=B[i][j])cnt++;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%c",cnt<=m*n/2?A[i][j]:(A[i][j]=='X'?'.':'X'));
		puts("");
	}
	return 0;
}
