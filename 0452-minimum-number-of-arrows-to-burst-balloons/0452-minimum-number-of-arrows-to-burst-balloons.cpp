
class Solution {
int mod = 1e9+7;
    public:
    int findMinArrowShots(vector<vector<int>>& points) {
            priority_queue<pair<int,int>> pq;
            for(int i=0;i<points.size();i++){
                pq.push({points[i][0],points[i][1]});
            }    
        vector<vector<int>>sorted;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            sorted.push_back({x.first,x.second});
        }
        int count = 0;
        
        long long int prev_x = sorted[0][0];
        long long int prev_y =sorted[0][1];
        for(int i=0;i<sorted.size();i++){
            cout<<prev_x<<" "<<prev_y<<" "<<i<<endl;
            if(i==0){
                count++;
            }else{
                
                long long int diff_curr = ((sorted[i][1]%(mod)))-(sorted[i][0]%(mod));
                long long int diff_inter = (prev_x-sorted[i][0])%(mod);
                
                if(diff_curr>=diff_inter){
                    
                    if(prev_y<sorted[i][1]){
                        
                    }else{
                    prev_y = sorted[i][1];
                    }
                }else{
                    prev_x = sorted[i][0];
                    prev_y = sorted[i][1];
                    cout<<prev_x<<" "<<prev_y<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};