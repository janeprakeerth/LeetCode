class Solution {
public:
    int compress(vector<char>& chars) {
        vector<string>c;
        
        int cnt = 0;
        for(int i=0;i<chars.size();i++){
            if(i==0){
                string x;
                x+=chars[i];
                c.push_back(x);
                cnt++;
            }
            
            else if(chars[i]==chars[i-1]){
                cnt++;
            }else{
                if(cnt>1){
                    c.push_back(to_string(cnt));
                }
                cnt = 0;
                string x;
                x+=chars[i];
                c.push_back(x);
                cnt++;
            }
        }
        if(cnt>1){
            c.push_back(to_string(cnt));
        }
        vector<char>cb;
        for(int i=0;i<c.size();i++){
            for(int j=0;j<c[i].length();j++){
                cb.push_back(c[i][j]);
            }
        }
        cout<<cb.size()<<endl;
        for(int i=0;i<cb.size();i++){
            chars[i] = cb[i];
        }
        return cb.size();
    }
};