class KthLargest {
public:
    int limit;
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (int num : nums) {
            pq.push(num);
            cnt++;
            if (cnt > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        cnt++;
        if (cnt > limit) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */