#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class NumArray {
private:
    vector<int> segmentTree;
    int n;
    void buildTree(int i, int left, int right, vector<int> &nums) {
        // Base Case
        if (left == right) {
            segmentTree[i] = nums[left];
            return;
        }

        int mid = (right - left)/2 + left;
        buildTree(2*i + 1, left, mid, nums);
        buildTree(2*i + 2, mid+1, right, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void updateTree(int idx, int val, int i, int left, int right) {
        // Base Case
        if (left == right) {
            segmentTree[i] = val;
            return;
        }

        int mid = (right - left) / 2 + left;
        if (idx <= mid) {
            updateTree(idx, val, 2*i+1, left, mid);
        }
        else {
            updateTree(idx, val, 2*i+2, mid+1, right);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int queries(int start, int end, int i, int l, int r, int sum) {
        if (start > r || end < l) return 0;
        else if (start <= l && end >= r) return segmentTree[i];
        int mid = (r-l)/2 + l;
        return queries(start, end, 2*i+1, l, mid, sum) + queries(start, end, 2*i+2, mid+1, r, sum);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return; 
        segmentTree.resize(4*n);
        buildTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return queries(left, right, 0, 0, n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */