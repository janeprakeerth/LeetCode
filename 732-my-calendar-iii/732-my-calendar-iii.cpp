class MyCalendarThree {
public:
     map<int,int> m;
    int maxSum=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;
        for(auto i : m){
            sum+=i.second;
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */