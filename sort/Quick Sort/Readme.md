# Quick Sort & DP & stack to solve the problem

### First Quick Sort 
To sort the envelops using area => so we could use dp to look back state

### Then DP
if: dp[i] = max(dp[:i] (if dp[x] is a russian doll)) + 1
else: dp[i] = 1

### two stacks
in case no russian doll is found, use stacks to append at the beginning 
