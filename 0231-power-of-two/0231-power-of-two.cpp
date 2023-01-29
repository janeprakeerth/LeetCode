class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        if(n==-2147483648){
            return false;
        }
        int a = n-1;
        int b = n&a;
        cout<<b;
       
        if(b==0){
            return true;
        }else{
            return false;
        }
    }
};