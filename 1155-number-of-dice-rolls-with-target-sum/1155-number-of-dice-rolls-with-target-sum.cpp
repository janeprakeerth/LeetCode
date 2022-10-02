class Solution {
public:
    int dp[31][10001];
    int solve(int n,int k,int target){
        if(target==0 && n==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int tot = 0;
            for(int j=1;j<=k;j++){
                tot=(tot+solve(n-1,k,target-j))%(1000000007);
            }
        
        return dp[n][target]=tot;
    }
    int numRollsToTarget(int n, int k, int target) {
        for(int i=1;i<=30;i++){
            for(int j=1;j<=1000;j++){
                dp[i][j] = -1;
            }
        }
        return solve(n,k,target);
    }
};
