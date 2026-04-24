# DAA Mini Project

This repository contains three C implementations of core Design and Analysis of Algorithms (DAA) topics:

- Priority Scheduling using a Max Heap
- Floyd-Warshall (All-Pairs Shortest Path)
- Topological Sort (Kahn's Algorithm using Indegree)

## Project Structure

- `q1_priority_scheduler.c`: Max-heap based priority scheduler operations (`insert`, `extractMax`, `heapify`)
- `q2_floyd_warshall.c`: Floyd-Warshall shortest path matrix computation
- `q3_topological_sort.c`: Topological ordering of a DAG with cycle detection support
- `q1.exe`, `q2.exe`, `q3.exe`: Prebuilt Windows executables
- `TEAM_LEARNING_AND_DIVISION.md`: Detailed study and presentation guide split for 4 members

## How To Compile And Run (Windows, GCC)

1. Compile:

```powershell
gcc q1_priority_scheduler.c -o q1.exe
gcc q2_floyd_warshall.c -o q2.exe
gcc q3_topological_sort.c -o q3.exe
```

2. Run:

```powershell
.\q1.exe
.\q2.exe
.\q3.exe
```

## Current Program Outputs

### Q1 - Priority Scheduler

```text
Extracted Max: 30
Extracted Max: 20
```

### Q2 - Floyd-Warshall

```text
Shortest distance matrix:
0 3 INF
2 0 INF
9 7 0
```

### Q3 - Topological Sort

```text
Topological Order:
0 1 2
```

## Algorithm Summary

### 1) Priority Scheduler (Max Heap)

- Heap is 1-indexed (`heap[1]` is max).
- `insert` bubbles up a new value to maintain heap property.
- `extractMax` removes highest-priority element and re-heapifies.
- Time complexity:
- `insert`: `O(log n)`
- `extractMax`: `O(log n)`
- `peek max`: `O(1)`

### 2) Floyd-Warshall

- Uses dynamic programming on adjacency matrix.
- Repeatedly tries each vertex `k` as an intermediate node between all `(i, j)`.
- Update rule:
- `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
- Time complexity: `O(V^3)`
- Space complexity: `O(V^2)`

### 3) Topological Sort (Kahn's Algorithm)

- Start with all zero-indegree nodes in queue.
- Pop node, print it, reduce indegree of neighbors.
- If processed count is less than total nodes, graph has a cycle.
- Time complexity:
- Matrix-based version in this repo: `O(V^2)`

## Team Workflow

For a 4-member team split (ownership, learning goals, viva/script points, and demo strategy), use:

- `TEAM_LEARNING_AND_DIVISION.md`

## Notes

- Current examples use fixed small graphs/heaps for demonstration.
- These implementations are clean baseline versions suited for learning, lab demonstration, and viva explanation.
