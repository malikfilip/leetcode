class MedianFinder {
public:
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
    
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(minHeap.empty() || num > minHeap.top()){
            minHeap.push(num);
        }else{
            maxHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()){
            minHeap.push (maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size()  == maxHeap.size() + 2){
            maxHeap.push (minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        //Dogovorili smo se da nam je u minHeapu uvek jedan element vise ako je broj elemenata u nizu nepara
        if(minHeap.size() > maxHeap.size()) return minHeap.top();
        return ( maxHeap.top()+minHeap.top() ) / 2.0;
    }
};
