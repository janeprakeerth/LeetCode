class Solution {
public:
    int dp[100];
    
    int op(vector<int>nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int x = nums[index]+op(nums,index+2);
        int y=-1;
        if(index+1<nums.size()){
        y = nums[index+1]+op(nums,index+3);
        }
        
        return dp[index] = x>y?x:y;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return op(nums,0);
    }
};