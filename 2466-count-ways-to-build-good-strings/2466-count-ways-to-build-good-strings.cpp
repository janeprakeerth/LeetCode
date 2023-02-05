class Solution {
public:
    int dp[100001];
    int ok = 1e9+7;
    int solve(int low,int high,int s,int zero,int one){
        if(s>high){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s]%ok;
        }
        int a,b;
        if(s>=low){
           
         a =solve(low,high,s+zero,zero,one)%ok;
         b = solve(low,high,s+one,zero,one)%ok;
            return dp[s] = (a+b+1)%ok;
        }else{
         a =solve(low,high,s+zero,zero,one)%ok;
         b = solve(low,high,s+one,zero,one)%ok;
        }
        
        return dp[s] = a+b%ok;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // string zero1;
        // string one1;
        // for(int i=0;i<zero;i++){
        //     zero1+='0';
        // }
        // for(int i=0;i<one;i++){
        //     one1+='1';
        // }
        memset(dp,-1,sizeof(dp));
        return solve(low,high,0,zero,one)%ok;
    }
};