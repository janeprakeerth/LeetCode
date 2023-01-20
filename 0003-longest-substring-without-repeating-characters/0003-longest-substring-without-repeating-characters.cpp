class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        map<char,int>m;
        int max_count = INT_MIN;
        
        cout<<s.length()<<" ";
        while(end<s.length()){
            m[s[end]]++;
            if(m[s[end]]==2){
                int count = end - start;
                max_count = max(max_count,count);
                
                while(m[s[end]]>1){
                    m[s[start]]--;
                    start++;
                }
            }else{
                int count = end - start+1;
                max_count = max(max_count,count);
            }
            
            end++;
        }
        if(max_count==INT_MIN){
            return end-start;
        }
        return max_count;
    }
};