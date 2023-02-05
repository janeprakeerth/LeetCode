class Solution {
public:
    string sortSentence(string s) {
        map<int,string>m;
        int start = 0;
        // cout<<s.substr(4,8)<<endl;
        for(int i=0;i<=s.length();i++){
            if(s[i]==' '||i==s.length()){
                cout<<start<<" "<<i<<endl;
                // string x = s.substr(start,i-1);
                // cout<<x<<endl;
                
                m[s[i-1]-'0'] = s.substr(start,i-1-start);
                start = i+1;
            }
            
        }
        
        string x;
        for(auto ok:m){
            x = x+ok.second;
            x+=' ';
        }
        string y;
        for(int i=0;i<x.length()-1;i++){
            y+=x[i];
        }
        return y;
    }
};