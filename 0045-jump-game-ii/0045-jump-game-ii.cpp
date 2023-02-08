class Solution {
public:
   
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,INT_MAX,sizeof(dp));
        dp[0] = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<nums.size()){
                    if(dp[i+j]==-1){
                        dp[i+j] = dp[i]+1;
                    }else if(dp[i+j]>dp[i]){
                        dp[i+j] = dp[i]+1;
                    }
                }else{
                    break;
                }
            }
        }
        return dp[nums.size()-1];
        
    }
};