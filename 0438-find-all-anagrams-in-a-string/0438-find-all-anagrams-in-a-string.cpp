class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> m ;
        for(int i = 0  ; i <= p.length() ; i ++){
            m[p[i]]++;
        }
        map<char,int>m1;
        int i = 0 ; int j = p.length();
        for(int i=0;i<j;i++){
            m1[s[i]]++;
        }
        vector<int>nums;
        while(j <= s.length()){
            cout<<i<<" "<<j<<endl;
            int flag = 1;
            for(auto x : m1){
                if(m[x.first]!=m1[x.first]){
                    flag =0;
                    break;
                }
            }
            if(flag == 1){
                nums.push_back(i);
            }
            
            m1[s[j]]++;

            m1[s[i]]--;
            i++;j++;
        }
        
        return nums;
    }
};