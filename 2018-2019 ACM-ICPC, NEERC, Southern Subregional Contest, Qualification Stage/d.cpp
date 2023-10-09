#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;

    long long c[n];
    for (long long i = 0; i < n; ++i)
        cin >> c[i];

    vector<pair<long long, long long> > ans;
    unordered_map<long long, pair<long long, bool> > record;
    for (auto &a: c){
        if (record.find(a) == record.end()){
            if (a != 1)
                record[a] = make_pair(1, 0);
            else
                record[a] = make_pair(1, 1);
            ans.push_back(make_pair(1, a));
        }else{
            if (!record[a].second){
                ans.push_back(make_pair(a/ record[a].first, record[a].first));
                record[a].second = 1;
            }else{
                bool flag(false);
                for (long long i = record[a].first + 1; i * i <= a; ++i){
                    if (a % i == 0){
                        if (i * i == a){
                            record[a] = make_pair(i, 1);
                        }
                        else{
                            record[a] = make_pair(i, 0);
                        }
                        ans.push_back(make_pair(i, a / i));
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (auto &a: ans){
        cout << a.first << "  " << a.second << endl;
    }

    return 0;
}
