class Solution {
private:
    bool dfs(int node, int iniColor, vector<vector<int>> &graph, vector<int> &color) {
        color[node] = iniColor;
        for (int i : graph[node]) {
            if (color[i] == -1) {
                int nextColor = iniColor == 1? 0:1;
                if (!dfs(i, nextColor, graph, color)) return false;
            }
            if (color[i] == iniColor) return false;
        } 
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i=0; i<n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};