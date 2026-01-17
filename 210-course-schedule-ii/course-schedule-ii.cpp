class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses);
        for (vector<int> &it: prerequisites) {
            adjlist[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) q.emplace(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            order.push_back(node);
            q.pop();
            for (int course: adjlist[node]) {
                indegree[course]--;
                if (indegree[course] == 0) {
                    q.emplace(course);
                }
            }
        }
        if (order.size() == numCourses) return order;
        return {};
    }
};