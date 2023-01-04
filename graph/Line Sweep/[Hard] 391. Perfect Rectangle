class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        multiset<vector<int>> events;
        int minPt(INT_MAX), maxPt(INT_MIN);
        for (auto &rect: rectangles){
            events.insert({rect[1], 1, rect[0], rect[2]});
            events.insert({rect[3], 0, rect[0], rect[2]});
            minPt = min(minPt, rect[0]);
            maxPt = max(maxPt, rect[2]);
        }
        int beginY((*events.begin())[0]), crtY((*events.begin())[0]);
        stack<int> tmp, tmp2;
        tmp.push(INT_MIN);
        tmp2.push(INT_MIN);
        for (auto &a: events){
            if (a[0] == beginY){
                if (a[1] == 1 && a[2] == minPt) minPt = a[3];
                else return false;
                continue;
            }

            if (a[0] == crtY){
                if (a[1] == 0) {
                    if (a[2] == tmp.top()) {
                        tmp.pop();
                        tmp.push(a[3]);
                    }else if (a[2] > tmp.top()){
                        tmp.push(a[2]);
                        tmp.push(a[3]);
                    }else return false;
                }
                else {
                    if (a[2] == tmp2.top()) {
                        tmp2.pop();
                        tmp2.push(a[3]);
                    }else if (a[2] > tmp2.top()){
                        tmp2.push(a[2]);
                        tmp2.push(a[3]);
                    }else return false;
                }
            }else{
                while (!tmp.empty() && !tmp2.empty()){
                    if (tmp.top() == tmp2.top()){
                        tmp.pop();
                        tmp2.pop();
                    }else return false;
                }
                if (tmp.empty() && tmp2.empty() && a[1] == 0){
                    crtY = a[0];
                    tmp.push(INT_MIN);
                    tmp2.push(INT_MIN);
                    tmp.push(a[2]);
                    tmp.push(a[3]);
                }else return false;
            }
        }
        if (minPt != maxPt) return false;
        return true;
    }
};
