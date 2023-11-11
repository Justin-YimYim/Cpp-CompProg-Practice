#include <bits/stdc++.h>

using namespace std;

int n=0, m=0;

const int M = 1e6;
int cnt=0;
int visited[2 * M + 5];
char ans[M + 5];
bool t[2 * M];
bool f[2 * M];

struct edge{
	int y, last_edge;
	long long weight;
};

long head[4 * M];
edge Edges[4 * M];
long ct=0;

void insertEdge(int x, int y, long long weight){
	int last_edge = head[x];
	head[x] = ++ct;
	Edges[ct].y = y;
    Edges[ct].last_edge = last_edge;
    Edges[ct].weight = weight;
}


vector<int> vec(M + 5);

void type1(int target){
    insertEdge(0, target, 1);
}

void type2(int target, int ptr){
    cnt++;
    for (int i =0; i< ptr;++i){
        int &a = vec[i];
        insertEdge(a, 2 * m + cnt, 1);
        visited[cnt]++;
    }
    insertEdge(2 * m + cnt, target, 1);
}

void dfs(int i){
    if (head[i] == 0x80808080) return;
    for (int it = head[i]; it != 0x80808080; it = Edges[it].last_edge){
        // cout << Edges[it].last_edge << " " << Edges[it].y << endl;
        int nxt = Edges[it].y;
        if (nxt <= 2 * m){
            if (nxt > m){
                if (f[nxt - m] == 0){
                    if (t[nxt - m] == 1){
                        cout << "conflict\n";
                        exit(0);
                    }
                    f[nxt - m] = 1;
                    dfs(nxt);
                }
            }else{
                if (t[nxt] == 0){
                    if (f[nxt] == 1){
                        cout << "conflict\n";
                        exit(0);
                    }
                    t[nxt] = 1;
                    dfs(nxt);
                }
            }
        }else{
            if (visited[nxt - 2*m]){
                visited[nxt - 2*m]--;
                if (visited[nxt - 2*m] == 0){
                    dfs(nxt);
                }
            }
        }
    }
}

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0);
    memset(head, 0x80, sizeof(head));
    memset(visited,0,sizeof(visited));
    memset(t,0,sizeof(t));
    memset(f,0,sizeof(f));

    n = read(), m = read();
    // 0 = s
    // loop through both unordered_set and see whether conflict
    for (int i=0;i<n;++i){
        string s, tmp;
        char ch = getchar();
        int ptr(0);
        int x;
        bool flag(false);
        while (ch != '\n' && ch != EOF){
            s += ch;
            ch = getchar();
        }
        if (s[s.size() - 1] == ' ')
            s.pop_back();
        
        for (auto &a: s){
            if (a != ' ' && a != '!' && a != '>' && a != '-')
                tmp += a;
            else if (a == ' '){
                if (!tmp.empty()){
                    vec[ptr] = std::stoi(tmp);
                    ptr++;
                }
                tmp = "";
            }else if (a == '!'){
                flag = true;
            }
        }
        if (tmp.empty()){
            tmp = vec[vec.size() - 1];
            vec.pop_back();
            ptr--;
            if (flag)
                x = std::stoi(tmp) + m;
            else x = std::stoi(tmp);
        }else{
            if (flag)
                x = std::stoi(tmp) + m;
            else x = std::stoi(tmp);
        }

        if (ptr >= 1)
            type2(x, ptr);
        else type1(x);
    }

    dfs(0);

    for (int i = 0; i <= m; i++)
        ans[i] = 'F';
    
    for (int i=1;i<=m;++i)
        if (t[i]) ans[i] = 'T';
    
    for (int i=1;i<=m;++i)
        cout << ans[i];
        
    cout << '\n';

    return 0;
}
