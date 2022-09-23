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
