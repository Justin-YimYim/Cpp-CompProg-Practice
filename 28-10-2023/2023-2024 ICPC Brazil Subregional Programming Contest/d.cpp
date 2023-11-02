#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define ll long long

using namespace std;
vector<vector<pii> > g;
vector<pii > road;
int dist[305];
ll ddp[305][305];
ll g2[305][305];

void FastIO(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

inline void buildDdp(int n){
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j){
        if (i == j)
            ddp[i][j] = 0;
        else if (g2[i][j] != 0) ddp[i][j] = g2[i][j];
        else ddp[i][j] = 0x7f7f7f7f;
    }

    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        ddp[i][j] = min(ddp[i][j], ddp[i][k] + ddp[k][j]);
}

int dijkstra(int n, pii rd){
    memset(dist, 0x7f, sizeof(dist));
    set<pii> pq;
 
    // {weight, vertex}
    pq.insert(make_pair(0, rd.first));
    dist[rd.first] = 0;
 
    while(!pq.empty()){
        int u = pq.begin()->second;
        int w = pq.begin()->first;
        pq.erase(pq.begin());
        if (u == rd.second) break;
        if (w > dist[u]) continue;
        for (auto &v: g[u]){
            if (u == rd.first && v.first == rd.second || u == rd.second && v.first == rd.first)
            continue;
            if (dist[v.first] > dist[u] + v.second){
                auto it = pq.find(make_pair(dist[v.first], v.first));
                if (it != pq.end()) pq.erase(it);
                dist[v.first] = dist[u] + v.second;
                pq.insert(make_pair(dist[v.first], v.first));
            }
        }
    }
    return dist[rd.second] == 0x7f7f7f7f? -1: dist[rd.second];
}
 
int main(){
    FastIO();
    int n,m;
    cin>>n>>m;
    memset(g2, 0, sizeof(g2));
    g = vector<vector<pii> > (n+1);
    road = vector<pii> (m);
    for (int i=0;i<m;++i){
        int u,v,l;
        cin>>u>>v>>l;
    
        road[i].first = u;
        road[i].second = v;
        g[u].emplace_back(v, l);
        g[v].emplace_back(u, l);
        g2[u][v]=l;
        g2[v][u]=l;
    }
 
    memset(ddp, 0x7f, sizeof(ddp));
    buildDdp(n);

    for (auto &rd: road){

        if (ddp[rd.first][rd.second] < g2[rd.first][rd.second])
            cout << ddp[rd.first][rd.second] << '\n';
        else{
            cout << dijkstra(n, rd) << '\n';
        }
    }
    return 0;
}
