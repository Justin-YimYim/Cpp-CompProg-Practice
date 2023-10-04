# Dynamic programming
## types of dp
- State transfer dp
- Combinatorial dp/ dp on graph space
### It is brute force but use (min/ max) to prune impossible path if it is a combinatorial question
### IS ALL ABOUT STATE TRANSFER
- Intialize
- Define current state
- Define ways to transfer => the more way, the more direction dp could be inherit
### Backward vs Forward (same dimension dp)
- Forward means condition depends on past
- Backward means condition depends on future
### Top-down vs bottom up (+1 dimension dp)
- Used in string (See strange printer)
### cherry pick 4 stage
- ** for loop is hard to do pruning
- ** while loop is easier
### When cant think of forward think of other direction
### Search on state vs space
- could prune the space

### diagonal dp for optimization
dp_i-k_j-k can optimized into dp_i-j
--> i - j means unselected items --> if monotonicity for unselected items is true, then yes 
