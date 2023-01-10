class Solution {
public:
    int dp[101][101];
    
    int solve(int m,int n){
        if(m==1 && n==1){
            return 1;
        }
        if(m<1 || n<1){
            return 0;
        }
        
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up = solve(m-1,n);
        int left = solve(m,n-1);
        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1;
            }
        }
        cout<<dp[5][5];
        int x = solve(m,n);
        return x;
    }
};