class Solution {
private:
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> safeNodes, indegree(n, 0);
        for (int i=0; i<graph.size(); i++) {
            for (int j:graph[i]) {
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            for (int i:adjRev[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};