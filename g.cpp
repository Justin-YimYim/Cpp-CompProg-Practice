#include <bits/stdc++.h>

using namespace std;

int mp[10005][10005];

struct pt {
    pt(double i, double j): x(i), y(j){}
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = true) {
    auto func = [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    };
    pt p0 = *min_element(a.begin(), a.end(), func);
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

int main(){
    std::ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
    int c;
    cin>>c;

    vector<pt> points;
    for (int i=1; i<=c; ++i){
        int x, y;
        cin>>x>>y;
        mp[x][y] = i;
        points.push_back(pt(x, y));
    }

    convex_hull(points);
    set<int> ans;
    for (auto &a: points)
        ans.insert(mp[int(a.x)][int(a.y)]);
    
    for (auto &a: ans)
        cout << a << ' ';
    cout << '\n';
    return 0;
}