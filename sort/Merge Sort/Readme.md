# Merge Sort with Variation
### Basic Algorithm
- Divide and conquer
- mergeSort(left)
- mergeSort(right)
- merge
### Variation
- Could add dimension to record information when doing merge
  -  Such as the swapping/ position information
- In merge
  - By adding position information, we could record how many times the current element go left/ right
  - Then, loop the sorted array at once. We could find out how many same element on left. 
  - We could go number of larger/ same/ smaller by merge sort
