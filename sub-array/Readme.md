# Prefix Sum
- Query: range => Find sum of range / Modification: null
# 差分序列
- Query: index / Modification: Add/ Subtract to a block
# Sparse 
- To use a map to map value to preven prefix sum overflow
# Block Algorithm
- Quite useless
- The concept is to define into seperate block and brute force search the modified block
# Sparse Table (For query min, max over block)
- Could not be modified
- Using dp
# Segment Tree -> improvement of sparse table
### Used A lot in counting problems
- Space Compexity = 2 * leave number < 4n
- Query: range / Modify: range/ index 
- We could open a 4n array
  - And divide and conquer recursively call
- Single modification => find specific node and recursively update (logn)
- Range modification => lazy tag 懶人標記
  - Remember to propagate lazy tag during query
# Binary Indexed Tree
- Query: range/ index / Modify: the other
- Space Complexity: n
- [parent, currentNode] = segment
- Single modification: update all right node, and parent right node recursively by adding last bit until n
# Mo's Algorithm
- Offline Alogrithm (Read all modification and query first
