#include <bits/stdc++.h>

using namespace std;

signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        long long n, p;
        cin >> n >> p;
        long long ans(0);
        long long a[n];
        map<long long, long long> mp;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
        {
            long long tmp;
            cin >> tmp;
            mp[tmp] += a[i];
        }
        n--;
        ans += p;
        for (auto &a: mp){
            if (a.first >= p || n == 0)break;
            ans += a.first * min(n, a.second);
            n = max(0LL, n - a.second);
        }

        if (n){
            ans += n * p;
        }
        cout << ans << endl;
    }
    return 0;
}