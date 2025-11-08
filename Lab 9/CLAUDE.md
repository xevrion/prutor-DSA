# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and Run Workflow

This is a Prutor DSA Lab 9 assignment directory containing C++ implementations of graph algorithms. The workflow uses VSCode tasks for compilation and testing.

### Compilation and Testing

The standard workflow uses the VSCode build task configured in `.vscode/tasks.json`:

```bash
# Compile and run a specific question file with input/output redirection
g++ que1.cpp -o jspwTest && ./jspwTest < input.txt > output.txt
```

The build task automatically:
1. Copies the current file to `jspwTest.cpp`
2. Compiles with `g++` (no special flags required)
3. Runs the executable with `input.txt` as stdin
4. Redirects output to `output.txt`
5. Cleans up temporary files

### Manual Compilation

For individual question files:
```bash
g++ que1.cpp -o que1 && ./que1
# or with I/O redirection:
g++ que2.cpp -o que2 && ./que2 < input.txt > output.txt
```

## Codebase Structure

This directory contains 7 question implementations (que1.cpp through que7.cpp), each solving a specific graph algorithm problem:

- **que1.cpp**: BFS with k-th largest element (uses priority queue + BFS)
- **que2.cpp**: DFS with conditional sum (threshold-based filtering)
- **que3.cpp**: Eulerian cycle verification (incomplete implementation)
- **que4.cpp**: Minimum Spanning Tree using Kruskal's algorithm with Union-Find
- **que5.cpp**: Empty placeholder file
- **que6.cpp**: Floyd-Warshall shortest paths (incomplete - missing core algorithm loop)
- **que7.cpp**: All-pairs shortest paths for logistics optimization (incomplete)

### Graph Representation Patterns

Different questions use different graph representations:
- **Adjacency List**: `vector<vector<int>>` (que1, que2)
- **Edge Set**: `set<pair<int, int>>` (que3)
- **Edge List**: `vector<Edge>` with custom Edge class (que4)
- **Adjacency Matrix**: `vector<vector<int>>` (que6, que7)

### Input/Output Convention

- **input.txt**: Contains test input for the currently active question
- **output.txt**: Generated output from program execution
- Input format varies per question (see problem statements in each .cpp file header)

## Implementation Status

### Complete Implementations
- que1.cpp: BFS + Min-Heap for k-th largest ✓
- que2.cpp: DFS with threshold filtering ✓
- que4.cpp: Kruskal's MST with Union-Find ✓
- que6.cpp: Floyd-Warshall (initialization complete, core loop present) ✓

### Incomplete Implementations
- que3.cpp: Missing `verifyEuleriancycle()` function body (has syntax error on line 91: `sol.sol.verifyEuleriancycle`)
- que5.cpp: Empty file
- que7.cpp: Floyd-Warshall initialization present but missing the triple nested loop for shortest path computation

## Key Algorithms Used

- **BFS/DFS**: Standard graph traversal (que1, que2)
- **Union-Find**: Disjoint set with path compression and union by rank (que4)
- **Kruskal's Algorithm**: Greedy MST construction (que4)
- **Floyd-Warshall**: All-pairs shortest paths (que6, que7)
- **Priority Queue**: Min-heap for k-th largest element (que1)

## Common Patterns

### Graph Construction
Most questions use a simple linear graph for testing:
```cpp
vector<vector<int>> graph(n);
for (int i = 0; i < n - 1; ++i) {
    graph[i].push_back(i + 1);
    graph[i + 1].push_back(i);
}
```

### Infinity Handling
For shortest path problems:
```cpp
const int INF = numeric_limits<int>::max()/2; // Prevent overflow
// or
const int INF = 1e9;
```

### Standard Libraries Used
- `<iostream>`: I/O operations
- `<vector>`: Dynamic arrays, adjacency lists
- `<queue>`: BFS queue
- `<set>`: Edge storage with fast lookup
- `<unordered_set>`, `<unordered_map>`: Hash-based visited tracking
- `<algorithm>`: Sorting (for Kruskal's)
- `<limits>`: Numeric limits for INF values
