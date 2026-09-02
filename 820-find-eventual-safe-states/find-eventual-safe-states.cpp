class Solution {
    vector<vector<int>> reverseGraph(vector<vector<int>> &graph, vector<int>& indegree) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        for (int i = 0; i < n; i++) {
            for (int neightbor : graph[i]) {
                revGraph[neightbor].push_back(i); 
                indegree[i]++;
            }
        }
        return revGraph;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
    
        vector<int> indegree(n, 0);
        vector<vector<int>> revGraph = reverseGraph(graph, indegree);

        queue<int> q;
        vector<int> safeNode;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        
        while (!q.empty()) {
            int node = q.front();
            safeNode.push_back(node);
            q.pop();

            for (int neighbor :revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());

        return safeNode;
    }
};