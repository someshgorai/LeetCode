class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int minEle1 = -1e9, minEle2 = -1e9;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && minEle2 != nums[i]) {
                cnt1++;
                minEle1 = nums[i];
            }
            else if (cnt2 == 0 && minEle1 != nums[i]) {
                cnt2++;
                minEle2 = nums[i];
            }
            else if (nums[i] == minEle1) cnt1++;
            else if (nums[i] == minEle2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == minEle1) cnt1++;
            if (nums[i] == minEle2) cnt2++;
        }

        vector<int> ans;
        int mini = (int) n / 3 + 1;
        if (cnt1 >= mini) ans.push_back(minEle1);
        if (cnt2 >= mini) ans.push_back(minEle2);

        return ans;
    }
};