class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int count  = 0;
        for(int i=0;i<costs.size();i++){
            int num = coins-costs[i];
            
            if(num>=0){
                count++;
            }else{
                return count;
            }
            coins -=costs[i];
        }
        return count;
    }
};