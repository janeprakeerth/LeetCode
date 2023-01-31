class Solution {
public:
    int dp[101];
    int solve(vector<int>nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int a = nums[index]+solve(nums,index+2);
        int b = solve(nums,index+1);
        
        return dp[index] = max(a,b);
    }
    int rob(vector<int>& nums) {
        for(int i=0;i<101;i++){
            dp[i] = -1;
        }
        return solve(nums,0);
    }
};