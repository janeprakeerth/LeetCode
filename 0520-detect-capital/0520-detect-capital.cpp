class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isFirstCapital=false;
        bool isMiddleCapital = false;
        bool allCapital = true;
        
        for(int i=0;i<word.length();i++){
            if(i==0 && word[i]-65<=25){
                isFirstCapital = true;
            }else{
                if(word[i]-65<=25){
                    allCapital = allCapital && true;
                    isMiddleCapital = true;
                }else{
                    allCapital = false;
                }
            }
        }
        
        if(allCapital){
            return true;
        }else if(isFirstCapital &&!isMiddleCapital){
            return true;
        }else if(!isFirstCapital &&!isMiddleCapital){
            return true;
        }else{
            return false;
        }
    }
};