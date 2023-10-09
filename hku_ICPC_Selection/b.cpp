#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t, m;
    cin >> t >> m;
    signed long N[t], F[t];

    memset(N, 0, sizeof(t));
    memset(F, 0, sizeof(F));
    int a, b , c;
    cin >> a >> b >> c;

    N[0] = a;
    for (int i = 1; i < t; ++i){
        N[i] = (N[i - 1] * b + c) % 256;
    }

    for (int i = 0; i < t; ++i){
        cin >> F[i];
    }

    for (int i = 0; i < t; ++i){
        N[i] = (F[i] - N[i] + 256) % 256;
    }

    // for (auto &a: N){
    //     cout << a << " ";
    // }
    // cout << endl;
    int S[m];
    for (int i = 0; i< m; ++i){
        cin >> S[i];
    }

    int KMP[m];
    int crt = 0;
    int ptr = 1;
    KMP[0] = 0;
    while (ptr < m){
        if (S[crt] == S[ptr]){
            crt++;
            KMP[ptr] = crt;
            ptr++;
        }else{
            if (crt == 0){
                KMP[ptr] = 0;
                ptr++;
            }
            else 
                crt = KMP[crt - 1];
        }
    }

    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < t){
        if (N[i] == S[j]){
            i++;
            j++;
            if (j == m){
                ans.push_back(i - m + 1);
                j = KMP[j - 1];
            }
        }else{
            if (j > 0){
                j = KMP[j - 1];
            }else{
                i++;
            }
        }
    }

    cout << ans.size() << endl;
    if (ans.size() > 0){
        for (auto &a: ans){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
