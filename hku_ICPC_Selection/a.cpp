#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    long long n, X, Y, Z;
 
    cin >> n >> X >> Y >> Z;
 
    long long count(0);
 
    long long upper(Z / Y);
 
    long long tmp(0);
    while (n--){
        cin >> tmp;
        if (tmp >= X){
            count++;
        }
    }
 
    long long possible(count / 3);
 
    if (possible == 0 || upper == 0){
        cout << 0 << endl;
        return 0;
    }
 
    if (upper > possible)
        cout << upper - possible + 1 << endl;
    
    else 
        cout << 1 << endl;
    return 0;
 
}
