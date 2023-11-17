#include <bits/stdc++.h>

using namespace std;

struct node{
    string s;
    bool flag;
    unordered_map<string, int> hash;
    vector<node*> child;
    node* prt = nullptr;
    node(string t, bool f): s(t), flag(f){}  
};

void dfs(node* head, int& ans){
    if (head == nullptr) {
        return;
    }
    if (head->flag){
        ans++;
        return;
    }
    else{
        for (auto& chd: head->child){
            dfs(chd, ans);
        }
    }
}

void clean(node* head){
    // cout << head->s << " " << head->flag << '\n';
    if (head == nullptr) return;
    for (auto chd: head->child){
        clean(chd);
    }
    delete head;
}

void solve(){
    int ans(0);
    int n, m;
    cin>>n>>m;
    node* head = new node("", false);
    for (int i=0;i<n;++i){
        string tmp;
        cin>>tmp;
        
        vector<string> tokens;
        stringstream ss(tmp);
        string token;

        node *ptr = head;
        while (std::getline(ss, token, '/')) {
            tokens.push_back(token);
        }

        for (auto &a: tokens){
            if (ptr->hash.find(a) == ptr->hash.end()){
                int tmp(ptr->hash.size());
                ptr->hash[a] = tmp;
                node* t = new node(a, true);
                ptr->child.push_back(t);
                ptr->child[ptr->hash[a]]->prt = ptr;
            }
            ptr = ptr->child[ptr->hash[a]];
        }
    }

    for (int i=0;i<m;++i){
        string tmp;
        cin>>tmp;
        
        vector<string> tokens;
        stringstream ss(tmp);
        string token;

        node *ptr = head;
        while (std::getline(ss, token, '/')) {
            tokens.push_back(token);
        }

        for (auto &a: tokens){
            if (ptr->hash.find(a) == ptr->hash.end()){
                int tmp(ptr->hash.size());
                ptr->hash[a] = tmp;
                node* t = new node(a, false);
                ptr->child.push_back(t);
                ptr->child[ptr->hash[a]]->prt = ptr;
            }
            ptr = ptr->child[ptr->hash[a]];
        }
        while (ptr != nullptr){
            ptr->flag = false;
            ptr = ptr->prt;
        }
    }

    dfs(head, ans);
    clean(head);
    cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
