#include<bits/stdc++.h>
using namespace std;
int a[5],n=4,dp[20000],ans;
char s[20];
int ss[20],ssl;
int sl;
bool vis[20];
int get_ans(){
	stack<int>s1;
	stack<int>s3;
	stack<char>s2;
	for(int i=1;i<=sl;i++){
		if('0'<=s[i]&&s[i]<='9'){
			if('0'<=s[i-1]&&s[i]<='9'){
				int num=s1.top();
				s1.pop();
				s1.push(num*10+s[i]-'0');
			}
			else s1.push(s[i]-'0');
		}
		else{
			if(s[i]=='+'||s[i]=='-'){
				while(!s2.empty()&&s2.top()=='*'){
					int x1=s1.top();
					s1.pop();
					int x2=s1.top();
					s1.pop();
					s1.push(x1*x2);
					s2.pop();
				}
				s2.push(s[i]);
			}
			else s2.push(s[i]);
		}
	}
	while(!s2.empty()){
		int x2=s1.top();
		s1.pop();
		int x1=s1.top();
		s1.pop();
		if(s2.top()=='*')s1.push(x1*x2);
		if(s2.top()=='-')s1.push(x1-x2);
		if(s2.top()=='+')s1.push(x1+x2);
		s2.pop();
	}
//	cout<<s1.top()<<endl;
	return s1.top(); 
}
void solve(int num){
	if(num==n+1){
		if(sl==4)return;
//		printf("%d %s ",sl,s+1);
		int tp=get_ans();
		if(tp>=0&&dp[tp]==0)ans+=dp[tp]=1;
		return;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		s[++sl]=a[i]+'0';
		solve(num+1);
		if(num<n){
			s[++sl]='+';
			solve(num+1);
			s[sl]='-';
			solve(num+1);
			s[sl]='*';
			solve(num+1);
			s[sl--]='\0';
		}
		s[sl--]='\0';			
		vis[i]=0;
	}
 
}
int main(){
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	solve(1);
	printf("%d",ans);
	return 0;
}
