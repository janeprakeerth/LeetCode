class Solution {
public:
    
    vector<string>solve(int n){
        if(n==1){
            return {"0","1"};
        }
        vector<string>prev = solve(n-1);
        vector<string>curr;
        for(int i=0;i<prev.size();i++){
            string x = prev[i];
            curr.push_back("0"+x);
        }
        for(int i=prev.size()-1;i>=0;i--){
            string x = prev[i];
            curr.push_back("1"+x);
        }
        return curr;
    }
    int bintoNum(string x){
        int a = 1;
        int num = 0;
        for(int i=x.length()-1;i>=0;i--){
            if(x[i]=='1'){
               num+=a; 
            }
            a*=2;
        }
        return num;
    }
    vector<int>solve2(vector<string>ans){
        vector<int>num;
        for(int i=0;i<ans.size();i++){
            string x = ans[i];
            int a = bintoNum(x);
            num.push_back(a);
        }
        return num;
    }
    vector<int> grayCode(int n) {
        vector<string>nums = solve(n);
        vector<int>ans = solve2(nums);
        return ans;
    }
    
};