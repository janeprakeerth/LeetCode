class Solution {
    int dp[50];
public:
    int a = 0;
    int solve(int n,int index){
        if(index==n){
            return 1;
        }
        int x=0,y=0;
        if(dp[index]!=-1){
            return dp[index];
        }
        if(index==n-1){
             x = solve(n,index+1);
            a++;
        }else{
             x = solve(n,index+1);
             y = solve(n,index+2);
        }
        
        return dp[index]=x+y;
    }
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};