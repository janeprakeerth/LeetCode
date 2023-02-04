class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int ans = nums[0];
        int maxx  = INT_MIN;
        int flag= 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i]>0){
                flag = 1;
            }
            maxx = max(maxx,nums[i]);
        }
        if(flag == 0 ){
            return maxx;
        }
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0] < 0 ? 0 : nums[0];
        for(int i = 1 ; i < nums.size() ; i ++){
            int sum = dp[i-1] + nums[i];
            if(sum < 0 ){
                dp[i] = 0 ;
            }
            else{
                dp[i]= dp[i-1] + nums[i];
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};