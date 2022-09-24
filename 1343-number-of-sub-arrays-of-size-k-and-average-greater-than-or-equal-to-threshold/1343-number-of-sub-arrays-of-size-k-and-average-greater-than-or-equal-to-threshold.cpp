class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int start = 0;
        int end = k-1;
        int sum = 0;
        for(int i=start;i<=end;i++){
            sum+=arr[i];
        }
        int count = 0;
        if(sum/k>=threshold){
                count++;
        }
        for(int i =k;i<arr.size();i++){
            cout<<sum<<endl;
            sum-=arr[start];
            start+=1;
            sum+=arr[i];
            if(sum/k>=threshold){
                count++;
            }
        }
        
        return count;
    }
};