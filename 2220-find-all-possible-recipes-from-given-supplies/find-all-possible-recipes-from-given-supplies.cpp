class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;
        for (int i = 0; i < n; i++) {
            for (auto ingredient : ingredients[i]) {
                adj[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for (string supply : supplies) {
            q.push(supply);
        } 

        vector<string> order;
        while (!q.empty()) {
            string node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    order.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return order;
    }
};