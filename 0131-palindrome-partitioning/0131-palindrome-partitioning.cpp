class Solution {
public:
    
    vector<vector<string>>ans;
    bool isPalindrome(string s){
        string y = s;
        
        reverse(s.begin(), s.end()); 
        if(s==y){
            return true;
        }
        return false;
    }
    void solve(string s,int index,string a,vector<string>out){
        if(s.length()==index){
            if(a!=""&&isPalindrome(a)){
                cout<<a<<endl;
                out.push_back(a);
                ans.push_back(out);
            }
            return;
        }
        if(a!=""&&isPalindrome(a)){
            cout<<"is"<<a<<index<<endl;
            solve(s,index+1,a+s[index],out);
            out.push_back(a);
            solve(s,index,"",out);
        }else{
            solve(s,index+1,a+s[index],out);
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0,"",{});
        return ans;
    }
};