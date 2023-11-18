#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n,m;

const int N = 1e5 + 5;
const int M = 1000000 + 5;
// long long dp[N], dp2[N], dp3[N];
long long ans = 0;

map<int, pair< int, int> > st;
// unordered_map<int, vector<pii> > mst;
// unordered_set<int> component, component2;

void FastIO(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

struct edge{
	int y, last_edge;
	long long weight;
};

int head[N];
edge Edges[M];
int cnt=0;
void insertEdge(int x, int y, long long weight){
	int last_edge = head[x];
	head[x] = ++cnt;
	Edges[cnt].y = y;
	Edges[cnt].last_edge = last_edge;
	Edges[cnt].weight = weight;
}

struct unionFind{
    vector<int> root;
    unionFind(int n): root(n){
        iota(root.begin(), root.end(),0);
    }

    int findRoot(int i){
       if (root[i] == i) return root[i];
        root[i] =  findRoot(root[i]);
        return root[i];
    }

    void merge(int i, int j){
        int rooti = findRoot(i), rootj = findRoot(j);
        root[rootj] = rooti;
        root[j] = rooti;
    }
};

// pii dfs(int i, int prt){
//     long long crt(0);
//     long long num(1);
//     for (auto &a: mst[i]){
//         if (a.first != prt){
//             auto tmp = dfs(a.first, i);
//             crt += tmp.first + tmp.second * a.second;
//             num += tmp.second;
//         }
//     }
//     dp[i] = crt;
//     dp2[i] = num;
//     return make_pair(crt, num);
// }
// 
// void dfs2(int i, int prt, int b, int prtVal){
//     long long tmp = prtVal - dp2[i] * b + (n - dp2[i]) * b;
//     cout << i << " " << tmp << " " << b << '\n';
//     ans += tmp;
//     for (auto &a: mst[i]){
//         if (a.first != prt){
//             dfs2(a.first, i, a.second, tmp);
//         }
//     }
// }

void dfs(int i, int prt, long long crtMn){
    // cout << ans << "\n";
    for (int nxt = head[i]; nxt != 0x80808080; nxt = Edges[nxt].last_edge){
        // cout << nxt << '\n';
        if (Edges[nxt].y != prt){
            ans += min(crtMn, Edges[nxt].weight);
            dfs(Edges[nxt].y, i, min(crtMn, Edges[nxt].weight));
        }
    }
}

signed main(){
    FastIO();
    cin>>n>>m;
    for (int i=0;i<m;++i){
        int u, v, b;
        cin>>u>>v>>b;
        st.insert(make_pair(b, make_pair(u, v)));
    }

    memset(head, 0x80, sizeof(head));

    unionFind uf(n+5), uf2(n+5);

    auto it = st.rbegin();
    int smallestB(INT_MAX);
    while (it != st.rend()){
        int b = it->first;
        int u = it->second.first;
        int v = it->second.second;
        if (uf.findRoot(u) != uf.findRoot(v)){
            smallestB = min(b, smallestB);
            uf.merge(u, v);
        }
        it++;
    }

    auto it2 = st.find(smallestB);

    while (it2 != st.end()){
        int b = it2->first;
        int u = it2->second.first;
        int v = it2->second.second;
        // cout << b << " "<<u<<" "<<v<<'\n';
        if (uf2.findRoot(u) != uf2.findRoot(v)){
            uf2.merge(u, v);
            insertEdge(u, v, b);
            insertEdge(v, u, b);
        }
        it2++;
    }

    for (int i=1;i<=n;++i){
        dfs(i, 0, LLONG_MAX);
    }

    // for (auto &a: mst){
    //     cout << a.first << ":";
    //     for (auto &b: a.second){
    //         cout << b.first << "=" << b.second << " ";
    //     }
    //     cout << '\n';
    // }

    // dfs(1, 0);
    // dp[0] = dp[1];
    // dfs2(1, 0, 0, dp[0]);
    // for (int i=0;i<=n;++i){
    //     cout << dp2[i] << "\n";
    // }

    cout << ans / 2 << '\n';
    return 0;
}
