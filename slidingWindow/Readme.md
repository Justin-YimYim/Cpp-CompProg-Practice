# Sliding Window 
- Use cases: use to solve merging subsequence problem (mostly for string)
- Used with hashmap technique to reduce time:
1. instead of iterating the whole hashmap => you can use a variable to keep track of the remaining item in the map.
2. if the map[i] {which is the count} >= 0, remaining-- (for right_ptr going right)
3. if the map[i] {which is the count} > 0, remaining++ (for left_ptr going right)

# Sliding Windows on number array
- Use Deque
- Find max: Use it as a monotonic decreasing stack -> front max be largest, the second one will be the largest after front is poped
- Find range: minus front and push_back
