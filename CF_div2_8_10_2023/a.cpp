#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        long long cummulate(0);
        n--;
        while(n--){
            long long tmp;
            cin >> tmp;
            cummulate += tmp;
        }
        cout << -cummulate << endl;
    }
    return 0;
}