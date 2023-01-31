class Solution {
    int dp[50];
public:

    int solve(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a = solve(n-1);
        int b = solve(n-2);
        return dp[n] = a+b;
    }
    
    int climbStairs(int n) {
        for(int i=0;i<50;i++){
            dp[i] = -1;
        }
        return solve(n);
    }
};