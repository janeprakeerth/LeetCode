class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>x;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                x.push(i);
            }
        }
        vector<pair<int,int>>ok;
        map<int,int>processed;
        while(!x.empty()){
            int index = x.top();
            if(index==0){
                cout<<"going to zero"<<endl;
            }
            while(s[index]!=')' && index<s.size()){
                index++;
                if(s[index]==')' && processed[index]==1){
                    while(s[index]==')' && processed[index]==1){
                        index++;
                    }
                }
                
            }
            cout<<"processed"<<index<<endl;
            processed[index] = 1;
            // cout<<s<<endl;
            ok.push_back({x.top()+1,index});
            cout<<x.top()+1<<" "<<index-1<<endl;
            x.pop();
        }
        
        for(int i=0;i<ok.size();i++){
            reverse(s.begin()+ok[i].first,s.begin()+ok[i].second);
        }
        string p;
        int o = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='('&&s[i]!=')'){
                p +=s[i];
                                
            }
        }
        return p;
    }
};