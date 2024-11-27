// 3243. Shortest Distance After Road Addition Queries I
// in this question clearly we want to find the shortest distance from node 0 to n - 1 (last node), 
// where all the nodes have edge from i ===> i+1 (unidirectional), 0->1->2->3 initially,
// and then we will have some queries that is a new edge and after adding that edge we need to find the shortest distance

// Solution

// things to notice ===>   shortest distance in a 2D array
// shortest path ==> BFS or djistra's (will think of BFS first)

// so after every query (i.e. new edge added) we do a BFS traversal and find the minimum distance and put in an answer array

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();

        // create the adjacency list first and add the initially edges and nodes i ==> i+1
        vector<vector<int>> adj (n, vector<int>());
        for(int i = 0; i<n; i++) {
            adj[i].push_back(i+1);
        }
        
        vector<int> ans;

        // for every query will do a traversal
        for(int i = 0; i<m; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);  // adding the new edge (road)
            // pair of node and distance (level) from node 0
            queue <pair<int,int>> q;
            vector<bool> visited(n, false); // keep a visited array to not visit the same node again
            q.push({0, 0});
            visited[0] = true;
            while(!q.empty()) {
                auto nodePair = q.front();
                q.pop();
            
                int node = nodePair.first;
                int distance = nodePair.second;
            
                if(node == n-1) {
                    ans.push_back(distance);
                    break;
                }

                // traverse the adjacent nodes of current node
                for(auto adjNode: adj[node]) {
                    if(!visited[adjNode]) {
                        q.push({adjNode, distance + 1});
                        visited[adjNode] = true;
                    }
                }
            }
        }
        return ans;
    }
};
