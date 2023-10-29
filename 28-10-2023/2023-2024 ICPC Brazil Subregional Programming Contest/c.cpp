#include <bits/stdc++.h>

using namespace std;

long long arr[100007];
int ans[100007];
unordered_map<int, vector<int> > g;

void dfs(int pos, int prt, vector<int> mono){
    for (auto &a: g[pos]){
        if (a == prt) continue;
        auto it = lower_bound(mono.begin(), mono.end(), arr[a]);
        if (it == mono.end()){
            mono.push_back(arr[a]);
            ans[a] = mono.size();
            dfs(a, pos, mono);
            mono.pop_back();
        }else{
            auto tmp = *it;
            mono[it - mono.begin()] = arr[a];
            ans[a] = mono.size();
            dfs(a, pos, mono);
            mono[it - mono.begin()] = tmp;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for (int i = 1; i < n; i++){
        int x;
        cin>>x;
        g[x].push_back(i+1);
        g[i+1].push_back(x);
    }

    for (int i=1;i<=n;++i){
        cin>>arr[i];
    }

    vector<int> monoI;
    monoI.push_back(arr[1]);
    dfs(1, 0, monoI);
    for (int i=2; i <= n; ++i){
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}
