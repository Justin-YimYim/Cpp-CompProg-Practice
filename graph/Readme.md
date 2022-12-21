# Euler Circuit
### Algorithm (Hierholzer's Algorithm)
- while graph[current] not empty()
  - get one and delete one 
  - recursion
  - add new node
### Definition
- Each edge go once and only once
### Existence 
- All in == out
- All in == out, except one in = out + 1 and one out = in + 1
# Hamilton Circuit
### Definition
- Each vertex go once and only once
### Necessary Condition
- All nodes have a degree >= 2
# De Bruijn Graph (Could create an Eulerian Walk)
- Each edge for one k-mer
- Each node for one (k - 1)-mer
### Construction
- Genome: AAABBBBA
- K-mer: AAA, AAB, ABB, BBB, BBB, BBA
- K-1 mer: (AA, AA), (AA, AB)...
=> Construct De Bruijn graph but creating node from k-mer[0] and k-mer[1]
### De Bruijn to Euler to Hamilton
- Suffix + next => suffix transfer => all edges 
- All combinations and walk once => all nodes 
