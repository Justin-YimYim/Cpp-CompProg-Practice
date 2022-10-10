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
  &nbsp;mid = (left + right) >> 1;\
  &nbsp;if inside left:\
    &nbsp;&nbsp;right = mid - 1;\
  &nbsp;else if inside right:\
    &nbsp;&nbsp;left = mid + 1;\
  &nbsp;else found/ not found:\
    &nbsp;&nbsp;return mid;\
