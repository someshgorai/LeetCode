class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryLocation;
        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++) factoryLocation.push_back(f[0]);
        }

        int m = factoryLocation.size();
        vector<vector<long long>> dp(2, vector<long long>(m+1, 0));
        
        dp[0][m] = 1e12;

        for (int robotIdx = n-1; robotIdx >= 0; robotIdx--) {
            for (int factoryIdx = m-1; factoryIdx >= 0; factoryIdx--) {
                int robotPosition = robot[robotIdx];
                int factoryPosition = factoryLocation[factoryIdx];

                // Assign a robot to factory
                long long assign = abs(robotPosition - factoryPosition) + 
                            dp[1][factoryIdx + 1];

                // Skip this factory
                long long skip = dp[0][factoryIdx + 1];

                dp[0][factoryIdx] = min(assign, skip);
            }
            dp[1] = dp[0];
        }
        return dp[0][0];
    }
};