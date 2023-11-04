#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > virtualNode;
vector<vector<bool> > sgSt;
int arr[512];
int A[400005];
int sg[512];
int topo[512];

inline void construct(){
    for (int i=0;i<256;++i)
    for (int j=0;j<=7;j++)
    if (arr[i] > arr[i ^ (1 << j)] && arr[i^(1<<j)] != -1){
        virtualNode[i].push_back(i ^ (1 << j)); 
        topo[i ^ ( 1 << j)]++;
    }
    
}

inline void calSG(int idx){
    virtualNode.clear();
    memset(sg, 0x7f,sizeof(sg));

    construct();

    queue<int> q;
    for (int i=0;i<256;++i)
    if (topo[i] == 0){
        sg[i] = 1;
        q.push(i);
    }

    while (!q.empty()){
        auto crt = q.front();
        q.pop();
        for (auto nxt: virtualNode[crt]){
            topo[nxt]--;
            if (topo[nxt] == 0) q.push(nxt);
            sg[nxt] = min(sg[nxt], sg[crt] ^ 1);
        }
    }
}

inline void FastIO(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main(){
    FastIO();
    int n,m;
    cin>>n>>m;
    memset(topo, 0, sizeof(topo));
    memset(arr, 0xff, sizeof(arr));
    A[0] = 0x7f7f7f7f;

    for (int i=1;i<=n;++i){
        cin >>A[i];
        arr[A[i]] = i;
    }
    
    int cnt(n+1);
    bool flag(false);
    while (m--){
        int op, val;
        cin>>op>>val;
        if (op == 1){
            flag = false;
            A[cnt] = val;
            arr[val] = cnt;
            cnt++;
        }else if (val != arr[A[val]]){
            cout << "Grammy\n";
        }else if (flag) {
            if (sg[A[val]]) cout << "Alice\n";
            else cout << "Grammy\n";
        }else{
            calSG(cnt - 1);
            flag = true;
            if (sg[A[val]]) cout << "Alice\n";
            else cout << "Grammy\n";
        }
    }

    // for (int i=0;i<=20;i++){
    //     cout << i << ": ";
    //     for (auto &a: virtualNode[i])
    //         cout << a << " ";
    //     cout << endl;
    // }

    // for (int i = 0; i <= 20; i++){
    //     cout << i << "->" << sg[i] << " ";
    // }
    // cout << endl;
    return 0;
}
