class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int> (numCourses, 1e9));
        for (int i = 0; i < numCourses; i++) {
            adj[i][i] = 0;
        }

        for (auto pre : prerequisites) {
            adj[pre[0]][pre[1]] = 1; 
        }

        for (int via = 0; via < numCourses; via++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        vector<bool> ans;
        for (auto query : queries) {
            if (adj[query[0]][query[1]] == 1e9) ans.push_back(false);
            else ans.push_back(true);
        }

        return ans;
    }
};