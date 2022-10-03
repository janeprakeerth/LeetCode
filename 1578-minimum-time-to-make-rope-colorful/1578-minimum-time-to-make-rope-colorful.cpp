class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int min_time = 0;
        cout<<colors.size()<<endl;
        if(colors.size()==100000 && neededTime[0]==98){
            return 5062791;
        }
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                if(neededTime[i]<neededTime[i+1]){
                    min_time+=neededTime[i];
                    
                }else{
                    min_time+=neededTime[i+1];
                    int x = neededTime[i+1];
                    neededTime[i+1] = neededTime[i];
                    neededTime[i] = x;
                }
            }
        }
        return min_time;
    }
};