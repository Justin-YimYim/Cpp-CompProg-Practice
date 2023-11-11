#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >>n>>k;
    set<long long> arr;
    for (int i =0;i<n;++i){
        long long tmp;
        cin>>tmp;
        arr.insert(tmp);
    }
    
    long long ans(0);
    auto it = arr.rbegin();
    while (k--){
        ans += *it;
        it++;
    }
    cout << ans <<'\n';
    return 0;
}