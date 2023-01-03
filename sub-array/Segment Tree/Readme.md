### Technique for count 
- Could add -(1 << 32) as the lowest number such that we could start search from 0
- we could use upper_bound - tmp.begin() - 1 to locate the number that smaller/ equal to target
### 2d SegTree
- SegTree of SegTree
- Not recommend to use. Too time consuming to implement. And if not properly puring, it will have huge time complexity.
