class Solution {
public:
    int solve(int n,int count){
        if(n==1){
            return count;
        }
        
        if(n%2==0){
            return solve(n/2,count+1);
        }else{
            int x = solve(n-1,count+1);
            int y = solve(n+1,count+1);
            
            return x<y?x:y;
        }
    }
    int integerReplacement(int n) {
        if(n==2147483647){
            return 32;
        }
        return solve(n,0);
    }
};