class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>x = nums;
        sort(x.begin(),x.end());
        int start = 0;
        int num1=0,num2=0;
        int pos1=0,pos2=0;
        int end = x.size() - 1;
        while(start<end){
            if(x[start]+x[end]==target){
                num1 = x[start];
                num2 = x[end];
                break;
            }
            
            if(x[start]+x[end]>target){
                end--;
            }else{
                start++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                pos1 = i;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num2 && i!=pos1){
                pos2 = i;
            }
        }
      
        return {pos1,pos2};
    }
};