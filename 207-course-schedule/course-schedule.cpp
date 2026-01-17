class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses, 0);
        for (vector<int> it:prerequisites) {
            adjlist[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.emplace(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int course = q.front();
            cnt++;
            q.pop();
            for (int node : adjlist[course]) {
                indegree[node]--;
                if (indegree[node] == 0){
                    q.emplace(node);
                }
            }
        }
        if (cnt == numCourses) return true;
        return false;
    }
};