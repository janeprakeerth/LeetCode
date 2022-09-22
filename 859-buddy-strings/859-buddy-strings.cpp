class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        int start_index = -1;
        int end_index = -1;
        
        bool x= false,y = false;
        if(s==goal){
           
            int x = 0;
            map<char,int>m;
            
            for(int i=0;i<s.size();i++){
                m[s[i]]++;
                
                if(m[s[i]]==2){
                    return true;
                }
            }
            
            return false;
            
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i] && start_index==-1){
                start_index = i;
                x = true;
            }else if(s[i]!=goal[i]){
                end_index = i;
                y = true;
            }
            
            if(x&&y){
                break;
            }
        }
        if(x&&y){
        char c = s[start_index];
        s[start_index ] = s[end_index];
        s[end_index] = c;
            if(s==goal){
                return true;
            }else{
                return false;
            }
        
            }else{
            return false;
        }
    }
};