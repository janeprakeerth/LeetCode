class Solution {
public:
    int dp[101];
    int solve(string s,int index){
        if(index>=s.size()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int num1=0;
        int num2=0;
        if(s[index]=='0'){
            return 0;
        }else if(s[index]=='1' ||s[index]=='2'){
            string x;
            x+=s[index];
            string y;
            num1 = solve(s,index+1);
            if(s[index]=='2'){
                if(index+1<s.size()){
                if(s[index+1]=='7' ||s[index+1]=='8'||s[index+1]=='9'){

                }else{
                    y+=s[index];
                    y+=s[index+1];
                    num2 = solve(s,index+2);
                }
                }
            }else{
                if(index+1<s.size()){
                 y+=s[index];
                y+=s[index+1];
                num2 = solve(s,index+2);
                }
            } 
        }else{
            string x;
            x+=s[index];
            string y;
            num1 = solve(s,index+1);
        }
        return dp[index] = num1+num2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};