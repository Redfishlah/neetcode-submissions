class MedianFinder {
public:
    priority_queue<int> lheap;
    priority_queue<int, vector<int>, greater<int>> rheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lheap.push(num);
        rheap.push(lheap.top());
        lheap.pop();
        if(rheap.size() > lheap.size()){
            lheap.push(rheap.top());
            rheap.pop();
        }  
    }
    
    double findMedian() {
        if(lheap.size() > rheap.size()) return lheap.top();
        return (double) (lheap.top() + rheap.top())/ 2.0;
    }
};

