
# Eulerian Path and Circuit

## 1. Eulerian Path
### Definition:
An **Eulerian Path** is a path in a graph that visits every edge exactly once. Vertices may be visited multiple times, but edges cannot be revisited.

### Existence Conditions (for both directed and undirected graphs):
#### In a Directed Graph:
- At most one vertex has **out-degree − in-degree = 1** (starting vertex).
- At most one vertex has **in-degree − out-degree = 1** (ending vertex).
- All other vertices must have **in-degree = out-degree**.

#### In an Undirected Graph:
- Exactly zero or two vertices must have an odd degree.
- All other vertices must have even degrees.
- The graph must be connected.

## 2. Eulerian Circuit
### Definition:
An **Eulerian Circuit** is a cycle in a graph that visits every edge exactly once and starts and ends at the same vertex.

### Existence Conditions:
#### In a Directed Graph:
- Every vertex must have **in-degree = out-degree**.
- The graph must be **strongly connected**.

#### In an Undirected Graph:
- Every vertex must have an even degree.
- The graph must be connected.

---

## Recognizing Eulerian Path Problems

### Characteristics of Eulerian Path Problems:
1. **Edge-focused problems**:
   - You are tasked with finding a route or path that traverses every edge exactly once.
2. **Graph traversal requirements**:
   - The problem asks if you can find a way to traverse edges of a graph without repetition.
3. **Hints in the problem statement**:
   - The problem mentions routes, roads, or trails that must be traversed exactly once.
   - There is often a requirement to check connectivity and degree conditions for vertices.

### Example Problem Statements:
- "Can you find a route that crosses every bridge in a city exactly once?"
- "Find a path in a delivery network that uses every route exactly once."
- "Design a circular tour that covers all roads without repetition."

---

## Common DSA Problems Based on Eulerian Path

### Problem 1: Check if an Eulerian Path or Circuit Exists
- **Given**: A graph (directed or undirected).
- **Task**: Determine if the graph has an Eulerian Path or Circuit.
- **Solution**:
  1. Compute vertex degrees (in-degree and out-degree for directed graphs).
  2. Verify the conditions for the existence of an Eulerian Path or Circuit.

### Problem 2: Find an Eulerian Path or Circuit
- **Given**: A graph with an Eulerian Path or Circuit.
- **Task**: Find and print the Eulerian Path or Circuit.
- **Solution**:
  - Use **Hierholzer's Algorithm** to construct the path/circuit.

### Problem 3: Eulerian Path in a City
- **Given**: A list of bridges between islands.
- **Task**: Determine a route to cross all bridges exactly once (Eulerian Path) or return to the starting point (Eulerian Circuit).

### Problem 4: String Reconstruction Problem (Eulerian Path in Directed Graph)
- **Given**: A list of strings.
- **Task**: Reconstruct a single string that visits all substrings as edges exactly once.

---

## Steps to Solve Eulerian Path Problems

1. **Understand the Problem**:
   - Determine if the problem involves traversing edges of a graph exactly once.
   - Check if the graph is directed or undirected.

2. **Build the Graph**:
   - Represent the problem using a graph (adjacency list/matrix).

3. **Check Eulerian Path Conditions**:
   - Calculate degrees for each vertex.
   - Verify conditions based on whether the graph is directed or undirected.

4. **Apply Algorithms**:
   - If the problem asks to check for existence, verify the conditions.
   - If the problem asks to construct the path, use **Hierholzer's Algorithm**.

---

## Example Problem

### Problem Statement:
You are given a directed graph representing a city map. Each edge represents a one-way road. Determine if there is a route that visits every road exactly once, and if so, find such a route.

### Solution:
1. Build the graph using adjacency lists.
2. Calculate the in-degree and out-degree of each vertex.
3. Verify the Eulerian Path conditions:
   - At most one vertex has **out-degree − in-degree = 1**.
   - At most one vertex has **in-degree − out-degree = 1**.
   - All other vertices have **in-degree = out-degree**.
4. If conditions are satisfied, find the Eulerian Path using **Hierholzer's Algorithm**.

---

## Practice Problems

### LeetCode:
1. [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/): Use an Eulerian Path approach.
2. [Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs/): Similar to Eulerian Circuit.

### HackerRank:
- Eulerian Path Problem: Solve connectivity and traversal-based problems.

### Custom Problem:
- "Given a list of DNA fragments, reconstruct the sequence by traversing each fragment exactly once."
