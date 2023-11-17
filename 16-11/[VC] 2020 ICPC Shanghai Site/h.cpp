#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 1e3 + 5;
long long a[maxn], b[maxn], c[maxn];

void solve() {
    int n, k, ans(LLONG_MAX);
    cin >>n>>k;
    for (int i=0;i<k;++i)
        cin>>a[i];
    for (int i=0;i<k;++i)
        cin>>b[i];
    sort(a, a + k);
    sort(b, b + k);
    for (int j=0;j<k;++j){
        for(int i = 0;i < k;i++) {
            c[i] = (a[(i + j) % k] - b[i] + n) % n;
        }
        sort(c,c + k);
        ans = min(ans,c[k - 1]);
        ans = min(ans,n - c[0]);
        
        for(int i = 0;i < k - 1;i++) {
            ans = min(ans,2ll * c[i] + (n - c[i + 1]));
            ans = min(ans,2ll * (n - c[i + 1]) + c[i]);
        }
    }
    cout << ans << '\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
