#include <bits/stdc++.h>

using namespace std;

int arr[int(1e5)+5];


void dfs(unordered_map<int, vector<int> > &g, vector<vector<long long> >& dp, int prt, int crt){
    dp[crt][0] = 0;
    dp[crt][1] = arr[crt];
    dp[crt][2] = LONG_MAX;
    for (auto &a: g[crt]){
        if (a != prt){
            dfs(g, dp, crt, a);
            dp[crt][2] = min(dp[crt][2] + min(dp[a][1], dp[a][2]), dp[crt][0] + dp[a][1]); 
            dp[crt][0] = (dp[a][2] == LONG_MAX? LONG_MAX: dp[crt][0] + dp[a][2]);
            dp[crt][1] += min(min(dp[a][0], dp[a][1]), dp[a][2]);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<long long> > dp(n + 1, vector<long long> (3, LONG_MAX));
    for (int i=1;i<=n;++i)
        cin>>arr[i];
    unordered_map<int, vector<int> > g;
    for (int i=0;i<n-1;++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(g, dp, 0, 1);
    cout << min(dp[1][1], dp[1][2]) << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    solve();
    return 0;   
}
