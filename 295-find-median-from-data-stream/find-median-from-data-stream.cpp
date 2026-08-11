class MedianFinder {
public:
    int leftSize = 0, rightSize = 0;
    priority_queue<double, vector<double>, greater<double>> rightHeap;
    priority_queue<double> leftHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftSize == 0) {
            leftHeap.push(num);
            leftSize++;
            return;
        }
        
        if (leftHeap.top() <= num) {
            rightHeap.push(num);
            rightSize++;
        }
        else {
            leftHeap.push(num);
            leftSize++;
        }

        if (leftSize < rightSize) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
            rightSize--;
            leftSize++;
        }

        if (leftSize - 2 == rightSize) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
            leftSize--;
            rightSize++;
        }
    }
    
    double findMedian() {
        if (leftSize == rightSize) return (leftHeap.top() + rightHeap.top())/2;
        return leftHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */