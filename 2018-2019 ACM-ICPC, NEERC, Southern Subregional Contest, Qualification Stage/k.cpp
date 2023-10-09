#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >>n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    unordered_map<int, vector<int> > g;
    for (int i = 0; i < n; ++i){
        int countLess(0), countMore(0);
        for (int j = i; j < n; ++j){
            if (arr[j] >= m){
                countMore++;
                if (countMore > countLess){
                    g[i].push_back(j);
                }
            }else{
                countLess++;
                if (countMore > countLess){
                    g[i].push_back(j);
                }
            }
        }
    }

    bool walked[n + 1];
    memset(walked, 0, sizeof(walked));
    stack<pair<int, int> > stk;
    for (signed int it = g[0].size() - 1; it >= 0; --it)
        stk.push(make_pair(g[0][it] + 1, 1));
    walked[0] = 1;

    while (!stk.empty()){
        auto crt = stk.top();
        if (walked[crt.first]) {
            stk.pop();
            continue;
        }
        walked[crt.first] = 1;
        // cout << crt.first << " " << crt.second << endl;
        if (crt.first == n){
            cout << crt.second << endl;
            return 0;
        }
        stk.pop();

        for (signed int it = g[crt.first].size() - 1; it >= 0; --it){
            if (!walked[g[crt.first][it] + 1])
                stk.push(make_pair(g[crt.first][it] + 1, crt.second + 1));
        }
    }
    cout << 0 << endl;
    return 0;
}