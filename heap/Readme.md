# Self defined priority queue
using vint = vector<int>;
auto cmp = [](const vint &a, const vint &b){return a[0] > b[0];};
priority_queue<vint, vector<vint>, decltype(cmp)> heap(cmp);
  
