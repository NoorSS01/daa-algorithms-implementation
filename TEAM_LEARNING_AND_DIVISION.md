# Team Learning And Division Guide (4 Members)

This file is your detailed reference for learning, explaining, and presenting this mini project as a 4-member team.

Use this as:

- Study plan
- Speaking script base
- Presentation ownership map
- Viva preparation sheet

---

## 1. Project Goal (One-Line Intro)

"Our DAA mini project demonstrates three foundational algorithms in C: priority scheduling with heap, Floyd-Warshall shortest paths, and topological sorting for DAG processing."

---

## 2. Team Division Into 4 Parts

Assign as Member 1, 2, 3, 4 (replace with names later).

### Part A - Member 1: Priority Scheduling Using Max Heap

Own file:

- `q1_priority_scheduler.c`

Responsibilities:

- Explain heap structure and why it fits priority scheduling
- Explain all heap operations (`insert`, `heapify`, `extractMax`)
- Show sample run and interpret output

What to prepare:

- Definition of max heap
- Parent-child index formula (`left = 2*i`, `right = 2*i+1`)
- Time complexity of insert/extract

### Part B - Member 2: Floyd-Warshall Algorithm

Own file:

- `q2_floyd_warshall.c`

Responsibilities:

- Explain all-pairs shortest path problem
- Explain dynamic programming transition
- Show matrix updates conceptually and final output

What to prepare:

- Meaning of `INF`
- Why 3 nested loops are needed
- Time/space complexity and use cases

### Part C - Member 3: Topological Sort (Kahn's Algorithm)

Own file:

- `q3_topological_sort.c`

Responsibilities:

- Explain DAG and indegree concept
- Explain queue-based processing
- Explain cycle detection using processed node count

What to prepare:

- Difference between DAG and cyclic graph
- Why nodes with indegree 0 are starting points
- Output order interpretation

### Part D - Member 4: Integration, Testing, Complexity Comparison, Presentation Lead

Own scope:

- Repository-level understanding (all files)
- Build/run demonstration
- Complexity comparison table
- Final introduction and conclusion in presentation

Responsibilities:

- Introduce project objective and team flow
- Compare all three algorithms at a high level
- Demonstrate compilation and execution steps
- Handle Q&A bridge between members during viva

What to prepare:

- When to use each algorithm in real systems
- Practical limitations of each implementation
- Future improvements section

---

## 3. Detailed Explanation By File

## A) `q1_priority_scheduler.c` (Member 1)

### Core Idea

Priority queue is implemented using a max heap in an array:

- Higher value = higher priority
- Root always holds highest-priority element

### Function-Wise Breakdown

1. `swap(int *a, int *b)`
- Swaps two integers by pointer
- Utility used in heap operations

2. `insert(int value)`
- Insert at end (`heap[++size] = value`)
- Bubble up while parent is smaller
- Maintains max-heap property

3. `heapify(int i)`
- Fixes heap from index `i` downward
- Finds largest among parent, left, right
- Swaps with largest child and recurses

4. `extractMax()`
- If heap empty, returns `-1`
- Save root as `max`
- Move last element to root, reduce size
- Call `heapify(1)`
- Return extracted max

### Program Demo Flow

- Insert `10`, `30`, `20`
- First extract: `30`
- Second extract: `20`

### Complexity

- Insert: `O(log n)`
- Extract max: `O(log n)`
- Space (array): `O(n)`

### Viva Points

- Why array heap is faster than sorted insertion for repeated scheduling events
- Why root index starts at 1 in this implementation

---

## B) `q2_floyd_warshall.c` (Member 2)

### Core Idea

Find shortest path between every pair of vertices by considering each vertex as an intermediate node.

### Data Setup

- `V = 3` vertices
- `INF = 99999` means no direct edge
- `graph[V][V]` stores initial adjacency matrix
- `dist[V][V]` is working shortest-distance matrix

### Algorithm Steps

1. Copy graph to `dist`
2. For each `k` from `0` to `V-1`:
- Try improving every pair `(i, j)` through `k`
- If `dist[i][k] + dist[k][j] < dist[i][j]`, update `dist[i][j]`
3. Print final distance matrix

### Why It Works

At phase `k`, paths are allowed to use only vertices `0..k` as intermediate nodes.
After last phase, all possible intermediate nodes are considered.

### Complexity

- Time: `O(V^3)`
- Space: `O(V^2)`

### Viva Points

- Difference between single-source shortest path and all-pairs shortest path
- Role of dynamic programming in repeated subproblem reuse
- Mention: negative cycle detection can be added by checking diagonal values (`dist[i][i] < 0`)

---

## C) `q3_topological_sort.c` (Member 3)

### Core Idea

Topological sort gives a linear order of tasks such that for every directed edge `u -> v`, `u` appears before `v`.

### Data Structures

- `graph[MAX][MAX]`: adjacency matrix
- `indegree[MAX]`: count of incoming edges per node
- `queue[MAX]`: nodes ready to process (indegree 0)

### Algorithm Steps (Kahn's Method)

1. Push all nodes with `indegree == 0` into queue
2. Repeat until queue empty:
- Pop node, print it
- For every outgoing edge from this node, reduce neighbor indegree
- If neighbor indegree becomes 0, push to queue
3. Count processed nodes
4. If count != n, cycle exists

### Demo Graph In Code

- `0 -> 1`
- `1 -> 2`
- Output: `0 1 2`

### Complexity

- In this matrix implementation: `O(V^2)`
- In adjacency-list form: `O(V + E)`

### Viva Points

- Why this only works for DAGs
- How cycle detection is inferred without DFS

---

## D) Integration And Comparison (Member 4)

### Build And Run Demo Script

```powershell
gcc q1_priority_scheduler.c -o q1.exe
gcc q2_floyd_warshall.c -o q2.exe
gcc q3_topological_sort.c -o q3.exe

.\q1.exe
.\q2.exe
.\q3.exe
```

### Comparison Table

| Algorithm | Problem Type | Main Idea | Time Complexity | Best Use Case |
|---|---|---|---|---|
| Max Heap Priority Scheduler | Priority management | Keep max at root | `O(log n)` per insert/extract | CPU/task scheduling, event queues |
| Floyd-Warshall | All-pairs shortest path | DP over intermediate vertices | `O(V^3)` | Dense graph shortest paths |
| Topological Sort (Kahn) | Dependency ordering in DAG | Indegree + queue | `O(V^2)` here (`O(V+E)` with list) | Course planning, build pipelines |

### Suggested Team Presentation Flow

1. Member 4: Problem statement, objective, and architecture
2. Member 1: Heap priority scheduler deep dive
3. Member 2: Floyd-Warshall deep dive
4. Member 3: Topological sort deep dive
5. Member 4: Comparison, conclusion, future improvements

### Conclusion Script

"This project demonstrates three important DAA patterns: greedy-style priority processing through heaps, dynamic programming for global shortest paths, and graph-ordering through indegree processing. Together, these cover scheduling, path optimization, and dependency resolution."

---

## 4. Practice Questions For Team Rehearsal

1. Why is heap better than linear scan for repeated highest-priority extraction?
2. Why does Floyd-Warshall use three loops, and what does each loop represent?
3. What happens in topological sort if the graph contains a cycle?
4. Which algorithm here is most suitable for dependency management and why?
5. How can each implementation be scaled for larger inputs?

---

## 5. Optional Improvements (For Extra Marks)

1. Add user input support for all three programs.
2. Convert topological sort from adjacency matrix to adjacency list.
3. Add negative-cycle reporting in Floyd-Warshall.
4. Add menu-driven single executable combining all three algorithms.
5. Add test cases and expected output table for multiple scenarios.

---

## 6. Final Team Checklist

1. Replace "Member 1-4" with real names.
2. Ensure each member can explain at least one full file without reading notes.
3. Rehearse the demo command flow once before submission.
4. Keep this file open during preparation and use it as your speaking base.
