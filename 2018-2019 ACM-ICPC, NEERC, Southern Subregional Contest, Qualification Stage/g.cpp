#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        if (y != n && x != n){
            cout << "NO" << endl;
            return 0;
        }
        mp[min(x, y)]++;
    }

    vector<pair<int, int> > ans;
    queue<int> q;
    for (int i = 1; i < n; ++i){
        int last = n;
        if (mp[i] == 0){
            q.push(i);
        }else{
            while (mp[i] > 1){
                if (q.empty()){
                    cout << "NO" << endl;
                    return 0;
                }
                int crt = q.front();
                q.pop();
                ans.push_back(make_pair(last, crt));
                last = crt;
                mp[i]--;
            }
            ans.push_back(make_pair(last, i));
        }
    }

    cout << "YES" << endl;
    for (auto &a: ans){
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}