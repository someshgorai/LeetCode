class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int left = 0, right = n-1;
        int count = 0;
        while (left <= right) {
            if (left < right && (people[left] + people[right]) <= limit) {
                count++;
                left++;
                right--;
            }
            else {
                count++;
                right--;
            }
        }

        return count;
    }
};