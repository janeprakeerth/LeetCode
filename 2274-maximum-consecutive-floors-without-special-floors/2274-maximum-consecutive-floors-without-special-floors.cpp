class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxx = INT_MIN;
        for(int i=0;i<special.size()-1;i++){
            maxx = max(maxx,special[i+1]-special[i]-1);
        }
        maxx = max(maxx,special[0]-bottom);
        maxx = max(maxx,top-special[special.size()-1]);
        return maxx;
    }
};