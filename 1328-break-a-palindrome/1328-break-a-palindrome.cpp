class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool replace = true;
        for(int i=0;i<palindrome.size()/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                replace = false;
                break;
            }
        }
        if(replace){
            palindrome[palindrome.size()-1]='b';
        }
        if(palindrome.size()==1){
            return "";
        }
        return palindrome;
    }
};