# Algorithm
Search(array, target, low, high)
- Conditions: 
  - low + 1 == high: check both items and return
  - low > high: false
  - target == mid: return
- Search left: Search(array, target, low, mid)
- Search right: Search(array, target, mid, high)

# Comments/ Ideas
A part consist from monotonic structure could use Binary Search to search some value

# iterative methods 
Search(arr, target):\
left = 0 \
right = size() - 1\
while (left <= right):\
  mid = (left + right) >> 1;\
  if inside left:\
    right = mid - 1;\
  else if inside right:\
    left = mid + 1;\
  else found/ not found:\
    return mid;\
