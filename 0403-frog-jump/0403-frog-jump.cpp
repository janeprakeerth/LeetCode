class Solution {
public:
    int dp[2001][2001];
    bool solve(vector<int>stones,int index,int k){
        if(index==stones.size()-1){
            return true;
        }
        int a = k-1;
        int b = k;
        int c = k+1;
        
        bool call1 = false,call2 = false,call3 = false;
        if(dp[index][k]!=-1){
            cout<<index<<endl;
            return dp[index][k];
        }
        for(int i=index+1;i<stones.size();i++){
            int dist = stones[i]-stones[index];
            if(dist==a){
               call1 = solve(stones,i,dist);
               dp[i][dist] = call1; 
            }
            if(dist==b){
               call2 = solve(stones,i,dist);
               dp[i][dist] = call2; 
            }
            if(dist==c){
               call3 = solve(stones,i,dist);
               dp[i][dist] = call3; 
            }
            
            if(dist>c){
                break;
            }
        }
        return dp[index][k] = call1||call2||call3;
    }
    bool canCross(vector<int>& stones) {
        for(int i=0;i<2001;i++){
            for(int j=0;j<2001;j++){
                dp[i][j] = -1;
            }
        }
        return solve(stones,0,0);
    }
};