#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

int dp[505][505][7];

int mp[300];
char mp2[7];

string n;
int m;

int find(int l, int r, char& color){
    // cout << l << " " << r << " " << color << '\n';
    if (dp[l][r][mp[color]] != 0x80808080) return dp[l][r][mp[color]];

    int l1, l2, tmp(0x80808080);
    for (int i=l;i<r;++i){
        l1 = find(l, i, color), l2 = find(i + 1, r, color);
        if (l1 == -1 || l2 == -1) continue;
        tmp = max(tmp, l1 + l2);
    }

    if (tmp == 0x80808080){
        dp[l][r][mp[color]] = -1;
        for (int i=0;i<7;++i)
            if (mp2[i] != color && find(l, r, mp2[i]) >= m) {
                dp[l][r][mp[color]] = 0;
                break;
            }
    }
    else 
        dp[l][r][mp[color]] = tmp;
    return dp[l][r][mp[color]];

}


int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    if (n.size() < m) {cout << "No\n"; return 0;}
    if (n.size() == 1) {cout << "Yes\n"; return 0;}
    memset(dp,0x80,sizeof(dp));

    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['M'] = 4;
    mp['Y'] = 5;
    mp['K'] = 6;

    mp2[0] = 'R';
    mp2[1] = 'G';
    mp2[2] = 'B';
    mp2[3] = 'C';
    mp2[4] = 'M';
    mp2[5] = 'Y';
    mp2[6] = 'K';

    for (int i=0;i<n.size();i++)
        dp[i][i][mp[n[i]]] = 1;

    int ans = find(1, n.size() - 1, n[0]);
    ans = max(find(0, n.size() - 2, n[n.size() - 1]), ans);

    // cout << ans << '\n';

    if (ans + 1 >= m) cout << "Yes\n";
    else cout << "No\n"; 

    return 0;
}
