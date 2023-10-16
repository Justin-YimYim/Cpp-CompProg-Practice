#include <bits/stdc++.h>

using namespace std;

struct Node{
public: 
    long long index;
    long long depth;
    Node* prt;
    Node(long long idx, long long dth, Node* pt): index(idx), depth(dth), prt(pt){}
};

void buildTree(unordered_map<long, vector<long> > &g, Node* crt, vector<Node* > &nodes){
    for (auto &a: g[crt->index]){
        if (a != crt->prt->index){
            Node * child = new Node(a, (crt->depth) + 1, crt);
            nodes[a] = child;
            buildTree(g, child, nodes);
        }
    }
}

void findPath(long long x, long long y, vector<Node* > nodes, vector<long> &pth, stack<long>& stk){
    auto depthx(nodes[x]->depth), depthy(nodes[y]->depth);
    if (x == y){
        pth.push_back(x);
        while (!stk.empty()){
            auto i = stk.top();
            stk.pop();
            pth.push_back(i);
        }
    }else{
        if (depthx == depthy){
            pth.push_back(x);
            stk.push(y);
            findPath(nodes[x]->prt->index, nodes[y]->prt->index, nodes, pth, stk);
        }else if (depthx > depthy){
            pth.push_back(x);
            findPath(nodes[x]->prt->index, y, nodes, pth, stk);
        }else{
            stk.push(y);
            findPath(x, nodes[y]->prt->index, nodes, pth, stk);
        }
    }
}

int exGCD(int a, int b, int& x, int& y){
	// a is the larger number	
	// gcd = ax + by
	if (a % b==0){
        x = 0;
        y = 1;
		return b;
    }

	long long gcd;
	gcd = exGCD(b, a % b, x, y);
    long long x_1, y_1;
    x_1 = y;
    y_1 = x + (- a / b * y);
    x = x_1;
    y = y_1;
    return gcd;
}

struct Point{
public:    
    Point(int x, int y): a(x), b(y){}
    int a;
    int b;
};

int Get_ans(Point p1,Point p2){
	int val=p2.b-p1.b;
	val%=p2.a;
	while(val<0)val+=p2.a;
	while(val>p2.a)val-=p2.a;
	int a=p1.a,b=-p2.a;
	int x,y,d=exGCD(a,b,x,y);
	if(val%d!=0)return 1e9;
	x*=val/d;y*=val/d;
	int p=b/d,q=a/d;
	if(x<0){
		int k=ceil((1.0-x)/p);
		x+=p*k,y-=q*k;
	}else if(x>=0){
		int k=(x-1)/p;
		x-=p*k,y+=q*k;
	}
	return a*x+p1.b;
}

void solve(){
    vector<string> a;
    long long n, m;
    cin>>n>>m;
    unordered_map<long, vector<long> > g;
    for (int i = 1; i < n; ++i){
        long long x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    Node * root = new Node(0, 0, nullptr);
    Node * start = new Node(1, 1, root);
    vector<Node* > nodes(n + 1, nullptr);
    nodes[1] = start;
    buildTree(g, start, nodes);
    while (m--){
        long long x_1, y_1, x_2, y_2;
        cin>>x_1>>y_1>>x_2>>y_2;
        vector<long> path1, path2;
        stack<long> tmp;
        findPath(x_1, y_1, nodes, path1, tmp);
        tmp = stack<long> ();
        findPath(x_2, y_2, nodes, path2, tmp);

        long long leng1((path1.size() - 1) * 2), leng2((path2.size() - 1) * 2);
        // long long tmpX, tmpY;
        // // cout << leng1 << " " << leng2 << endl;
        // if (leng1 < leng2){
        //     swap(leng1, leng2);
        //     swap(path1, path2);
        // }
        // long long gcd = exGCD(leng1, leng2, tmpX, tmpY);
        // cout << "GCD: " << gcd << ": " << tmpX << ": " << tmpY << endl;
        int ans(1e9);
        for (long long i = 0; i < long(path1.size()); ++i){
            for (long long j = 0; j < long(path2.size()); ++j){
                if (path1[i] == path2[j]){
                    // tmpY * multi * leng2 - tmpX * mutli * leng1 == i - j
                    // tmpX * mutli * leng1 + i = tmpY * multi * leng2 + j <- find smallest p for this linear combination
                    ans = min(ans, Get_ans(Point(leng1, i), Point(leng2, j)));
                    ans = min(ans, Get_ans(Point(leng1, i), Point(leng2, leng2 - j)));
                    ans = min(ans, Get_ans(Point(leng1, leng1 - i), Point(leng2, j)));
                    ans = min(ans, Get_ans(Point(leng1, leng1 - i), Point(leng2, leng2 - j)));
                }
            }
        }
        if (ans == 1e9)
            a.push_back("-1\n");
        else{
            ans = ans % leng1;
            if (ans >= path1.size()){
                a.push_back(to_string(path1[leng1 - ans]) + '\n');
            }else{
                a.push_back(to_string(path1[ans]) + '\n');
            }
        }
    }
    for (auto &i: a)
        cout<<i;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
