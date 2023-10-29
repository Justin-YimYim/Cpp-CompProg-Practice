#include <bits/stdc++.h>

using namespace std;

int dp[105][105], g[105][105];

void construct(int n){
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        dp[i][j] = g[i][j];
    


    for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
}

bool check(int n){
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j){
        if (dp[i][j] < g[i][j])return false;
    }
    return true;
}

int solve(int n){
    int ans(0);
    for (int i=0;i<n;++i)
    for (int j=i+1;j<n;++j)
    for (int k=0;k<n;++k){
        if (k==i||k==j)continue;
        if (dp[i][k]+dp[k][j]==g[i][j]){
            ans++;
            break;
        }
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    for (int j=0;j<n;++j){
        cin>>g[i][j];
    }

    construct(n);
    if (check(n)){
        cout<<solve(n)<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}