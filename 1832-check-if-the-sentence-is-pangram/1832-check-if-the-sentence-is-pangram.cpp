class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>m;
        for(int i=0;i<sentence.length();i++){
            m[sentence[i]]=1;
        }
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        
        for(int i=0;i<alpha.length();i++){
            if(m[alpha[i]]==0){
                cout<<"ok"<<endl;
                return false;
            }
        }
        return true;
    }
};