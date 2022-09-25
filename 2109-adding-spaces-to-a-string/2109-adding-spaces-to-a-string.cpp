class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int prev_size = s.size()-1;
        int space_size = spaces.size();
        int index = space_size;
        string ok;
        for(int i=0;i<index;i++){
            ok+=' ';
        }
        int new_size = s.size()-1;
        int k = spaces.size()-1;
        s+=ok;
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                j=i-1;
                break;
            }
        }
        int x = spaces.size()-1;
        cout<<j<<" "<<s.size()<<endl;
        for(int i=s.size()-1;i>=0;i--){
            if(x==-1){
                break;
            }
            if(j==spaces[x]){
                s[i] = s[j];
                s[i-1] = ' ';
                i--;
                x--;
                j--;
            }
            else{
                s[i] = s[j];
                j--;
            }
        }
        return s;
    }
};