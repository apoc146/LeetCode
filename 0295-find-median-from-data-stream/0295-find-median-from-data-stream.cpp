class MedianFinder {
public:
    priority_queue<int> bottom;
    priority_queue<int, vector<int>, greater<int>> top;
    int n1=0;
    int n2=0;
    MedianFinder() {
  
    }
    
    // Adds a number to the data structure.
    void addNum(int num) {
        //insert ele first
        if(bottom.size()==0 || num<bottom.top()){
            bottom.push(num);
        }else{
            top.push(num); 
        }
        
        //rebalance heaps
        if(bottom.size()>top.size()+1){
            top.push(bottom.top());
            bottom.pop();
        }else if(top.size() > bottom.size()){
            bottom.push(top.top());
            top.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(bottom.size()==top.size() ){
            return (bottom.top()+top.top())/2.0;
        }else{
            return bottom.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */