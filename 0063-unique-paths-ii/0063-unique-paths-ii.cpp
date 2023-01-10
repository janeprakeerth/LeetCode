class Solution {
public:
    int dp[101][101];
    int solve(int m,int n,vector<vector<int>>obstacleGrid){
        
        
        
        if(m<0||n<0){
            return 0;
        }
        if(obstacleGrid[m][n]==1){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        int up = solve(m-1,n,obstacleGrid);
        int left = solve(m,n-1,obstacleGrid);
        
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] =-1;
            }
        }
        return solve(m-1,n-1,obstacleGrid);
    }
};