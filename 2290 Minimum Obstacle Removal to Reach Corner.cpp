// 2290. Minimum Obstacle Removal to Reach Corner

/*
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

Example
Input: grid = [[0,1,1],
               [1,1,0],
               [1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.
  */

// *************************************Solution*********************************************
//
// For this problem we can consider it as a graph problem (not a dp problem since at any state we need the values for states that are not calculated yet)
// grid[i][j] is a vertex (node) and grid[i][j] is the edge weight from the adjacent cell

//we can use Dijkstra's Algorithm for this problem to find the minimum obstacles
// *******************************Why Dijstra's **********************
//
// Because we need to find a path such that we have minimum weight or obstacle from source to bottom right, in dijkstra's we find to all nodes
//******************************Why 0-1 BFS **************************
// whenever we have edge weights as 0 or 1 then we can use 0-1 BFS using Deque in place of Dijkstra's

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {0, -1, 0, +1};
        int delCol[] = {-1, 0, +1, 0};
        // Dijkstra's algorithm using set
        set<vector<int>> st; // {minObstacles, i, j} 
        vector<vector<int>> minObs(n, vector<int> (m, INT_MAX)); // initially not reachable to any node

        // starting node in our case is (0, 0) and distance or minimum obstacles to this is grid[0][0]
        minObs[0][0] = grid[0][0];
        st.insert({minObs[0][0], 0, 0});

        while(!st.empty()) {
            auto it = *(st.begin());
            int minObsYet = it[0];
            int row = it[1];
            int col = it[2];

            st.erase(it);

            for(int i = 0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                    continue;
                }

                if (minObs[newRow][newCol] > minObsYet + grid[newRow][newCol] ) {
                    if (minObs[newRow][newCol] != INT_MAX) { // already existed with other more obstacles
                        st.erase({minObs[newRow][newCol], newRow, newCol});
                    }
                    minObs[newRow][newCol] = minObsYet + grid[newRow][newCol];
                    st.insert({minObs[newRow][newCol], newRow, newCol});
                }
            }
        }
        return minObs[n-1][m-1];
    }
};
