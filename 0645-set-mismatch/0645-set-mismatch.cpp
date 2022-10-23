class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>ok;
        for(int i=1;i<=nums.size();i++){
            if(m[i]==2){
                ok.push_back(i);
                break;
            }
        }
        
        for(int i=1;i<=nums.size();i++){
            if(m[i]==0){
                ok.push_back(i);
                break;
            }
        }
        return ok;
    }
};