class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> stops;
        for (auto &obs : obstacles) {
            stops.insert({obs[0], obs[1]});
        }

        vector<pair<int,int>> dirs = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int x = 0, y = 0, dir = 0;
        int maxDisplace = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    if (stops.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxDisplace = max(maxDisplace, x*x + y*y);
                }
            }
        }

        return maxDisplace;
    }
};