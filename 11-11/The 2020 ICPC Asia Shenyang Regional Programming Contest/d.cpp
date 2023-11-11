#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;
long long n,ans,num,tot;
int dis[N], pos[N];
char a[N];

void test(){
    long long sum=0;
    for (int i=1;i<=tot;++i)
        dis[i]=pos[i]-pos[i-1];
    dis[tot+1]=n+1-pos[tot];
    for (int i=1;i<=tot+1;i++)
    for (int j=i+1;j<=tot+1;j+=2)
        sum+=dis[i]*dis[j];

    if (sum==ans){
        num++;
        for (int i=1;i<=n;++i)
            cout<<a[i];
        cout <<'\n';
        if (num==100) exit(0);
    }
}

void dfs(int x){
    if(x>n) {
        test();
        return;
    }
    a[x]='b', dfs(x+1);
    pos[++tot]=x;
    a[x]='r', dfs(x+1);
    --tot;
}

void loop(){
    int i, j;
    if (n & 1){
        i = n;
        j = n+1;
        }
    else {
        i = n+1;
        j = n+2;
        }
    while (i != n/2 && num < 100){
        a[i] = 'r';
        a[j] = 'r';
        for (int i=1;i<=n;++i) cout << a[i];
            cout << '\n';
        a[i] = 'b';
        a[j] = 'b';
        i--;
        j--;
        num++;
    }
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    if (n&1) ans=(n+1)*(n+1)/4;
    else ans=(n/2)*(n/2+1);
    cout << ans << '\n';

    for (int i=1;i<=n;i++) a[i] ='b';
    if (n <= 20){
        dfs(max(1LL, n-20));
    }else if (n < 200){
        a[n/2+1]='r';
        for (int i=1;i<=n;++i) cout << a[i];
        cout << '\n';
        num++;
        a[n/2+1]='b';
        a[n/2]='r';
        loop();
        if (num >= 100) return 0;
        a[n/2]='b';
        a[n/2-1]='r';
        pos[tot=1]=n/2-1;
        dfs(n/2);
    }else{
        a[n/2+1]='r';
        for (int i=1;i<=n;++i) cout << a[i];
        cout << '\n';
        num++;
        a[n/2+1]='b';
        a[n/2]='r';
        loop();
    }
    return 0;
}