#include <bits/stdc++.h>

using namespace std;

int dp[int(1e6) + 5];

int getGrain(int n){
    int ans(0);
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int build(int n){
    if (dp[n] == 0 && n != 0){
        int tmp = n - getGrain(n);
        dp[n] = 1 + build(tmp);
    }
    return dp[n];
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,k;
    cin>>n>>k;
    int mp[int(1e6)+7] = {};
    while (n--){
        int x;
        cin>>x;
        mp[x]++;
    }

    int ptr(INT_MAX);
    for (int i = 1e6 + 1; i > 0; i--){
        if (k <= mp[i]){
            ptr = i;
            break;
        }
        mp[i - getGrain(i)] += mp[i];
        k -= mp[i];
    }

    if (ptr == INT_MAX)
        cout << 0 << '\n';
    else
        cout << getGrain(ptr) << '\n';
    return 0;
}