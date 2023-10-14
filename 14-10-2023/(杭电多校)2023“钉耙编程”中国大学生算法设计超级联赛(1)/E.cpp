#include <bits/stdc++.h>

using namespace std;
long long pow(long long base,long long power, long long mod){
    long long result = 1;
        while (power > 0){
            if (power % 2 == 1)
                result = (result * base) % (mod);
            power /= 2;
            base = (base * base) % (mod);
        }

        return result;
}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
    vector<string> ans;
	long long t;
	cin >> t;
    long long mod(1e9+7LL);
	while (t--){
		long long n,m;
		cin>>n>>m;
		vector<long long> mp(n + 1);
		long long cnt(1);
		while (n--){
			string st;
			cin>>st;
			long long tmp(0);
			for (long long i = 0; i < m; i++){
				tmp = ((tmp * 131LL % mod) + int(st[i] - 'a')) % mod;
			}
			mp[cnt] = tmp;
            // cout << tmp << endl;
			for (long long i = 0; i < m; ++i){
                tmp = ((tmp - (int(st[i] - 'a') * pow(131LL, m - 1, mod)) % mod) + mod ) % mod;
				tmp = ((tmp * 131LL % mod) + int(st[i] - 'a')) % mod;
                mp[cnt] = min(mp[cnt], tmp);
			}
			cnt++;
		}
		long long q;
		cin>>q;
        // for (auto &a: mp){
        //     cout << a << endl;
        // }


		while(q--){
			long long x,y;
			cin>>x>>y;
			if (mp[x] == mp[y])
				ans.push_back("Yes\n");
			else
				ans.push_back("No\n");
		}
	}

    for (auto &a: ans)
        cout << a;
    return 0;
}
