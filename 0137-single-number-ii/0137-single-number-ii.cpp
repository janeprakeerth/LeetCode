class Solution {
public:
    
    void updatearr(vector<int>&sumarr,int num){
        for(int i=0;i<32;i++){
            int n = num &(1<<i);
            if(n){
                sumarr[i]++;
            }
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int>sumarr(32,0);
        for(auto x:nums){
            updatearr(sumarr,x);
        }
        int n = 0;
        for(int i=0;i<32;i++){
            int a = sumarr[i]%3;
            if(a){
                n = n+(1<<i);
            }
        }
        return n;
    }
};