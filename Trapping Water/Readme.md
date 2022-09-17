4 Solutions:
Try to simplify the algorithm. Think in two driections => 
- Big area - small area (which lead to heavy computation) & recursion
- Find each item store water 

1. Brute Force => find water could be hold for each index, by finding min(Left_Max, Right_max)
2. Monotonic Stack => 
- Make it into bucket
- Recursively find stored water by min(left, right) * length - stored water area
3. DP (from brute force) 
- From left: Increase state by state current water stored
- From right: Increase state by state current water stored
- Find min(left[i], right[i]) for each i
4. two pointer (Developed from DP)
- Observation: left < LeftMAX && left < heighRight => left will be filled
