#include <bits/stdc++.h>

using namespace std;
long long pow2(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a %mod;
    b >>= 1;
  }
  return res;
}

vector<long> SieveOfEratosthenes(int n)
{
    vector<long> ans;
    vector<bool> prime(n, 1);
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p=2; p<=n; p++)
       if (prime[p])
          ans.push_back(p);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long mod(998244353);
    long long n; 
    cin >> n;
    vector<long> primes(SieveOfEratosthenes(1e5 + 10));
    long long arr[n + 1];
    for (int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    long long dp[n + 1];

    for (long long i = n; i > 0; --i){
        dp[i] = arr[i];
        for (auto &a: primes){
            if (i * a <= n){
                dp[i] = max(dp[i], dp[i * a]);
            }else break;
        }
    }

    map<long long, long long> mp;
    long long ans(0);
    for (int i = 1; i <= n; i++)
        mp[dp[i]]++;
    
    for (auto a = mp.rbegin(); a != mp.rend(); a++){
        // cout << a->first << " " << a->second << endl;
        while (a->second != 0){
            (ans = ans % mod + ((pow2(2, n - 1, mod)) * ((a->first) % mod) % mod)) %= mod;
            // cout << ans << endl;
            a->second--;
            n--;
        }
    }

    cout << ans << endl;
    return 0;
}