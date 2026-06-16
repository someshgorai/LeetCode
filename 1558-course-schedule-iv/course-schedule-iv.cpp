class Solution {
public:
    int findUltiCourse(int node, vector<int> &ultiCourse) {
        if (ultiCourse[node] == node) return node;
        return ultiCourse[node] = findUltiCourse(ultiCourse[node], ultiCourse);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<unordered_set<int>> preCourse(numCourses);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                preCourse[neighbor].insert(node);
                for (auto pre : preCourse[node]) {
                    preCourse[neighbor].insert(pre);
                } 
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        vector<bool> ans;
        
        for (auto query : queries) {
            int course1 = query[0];
            int course2 = query[1];
            if (preCourse[course2].empty()) ans.push_back(false);
            else if (preCourse[course2].find(course1) != preCourse[course2].end()) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};