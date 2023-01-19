class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int ori_1 = str1.length();
        int ori_2 = str2.length();
        int len_1 = str1.length();
        int len_2 = str2.length();
        string ans;
        if(len_1<len_2){
            int cnt = 0;
            while(len_1>0){
                string temp;
                string test_1;
                string test_2;
                for(int i=0;i<len_1;i++){
                    temp+=str1[i];
                }
                int x =ori_1/len_1;
                
                int y = len_2/len_1;
                test_1 = temp;
                test_2 = temp;
                for(int i=0;i<x-1;i++){
                    test_1+=temp;
                }
                for(int i=0;i<y-1;i++){
                    test_2+=temp;
                }
                if(test_1==str1 && test_2==str2){
                    return temp;
                }
                len_1--;
                cnt++;
            }
        }else{
            int cnt = 0;
            while(len_2>0){
                string temp;
                string test_1;
                string test_2;
                for(int i=0;i<len_2;i++){
                    temp+=str2[i];
                }
                int x =ori_2/len_2;
                int y = len_1/len_2;
                test_1 = temp;
                test_2 = temp;
                for(int i=0;i<x-1;i++){
                    test_2+=temp;
                }
                for(int i=0;i<y-1;i++){
                    test_1+=temp;
                }
                cout<<test_1<<endl;
                if(test_2==str2 && test_1==str1){
                    return temp;
                }
                len_2--;
                cnt++;
            }
        }
        return ans;
    }
};