class Solution {
public:
    int dp[201][201];
    int ok(vector<vector<int>>&solve,int x,int y){
        if(x==solve.size()-1){
            return solve[x][y];
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int a = solve[x][y]+ok(solve,x+1,y);
        int b = solve[x][y]+ok(solve,x+1,y+1);
        return dp[x][y] = min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                dp[i][j] = -1;
            }
        }
        return ok(triangle,0,0);
    }
};