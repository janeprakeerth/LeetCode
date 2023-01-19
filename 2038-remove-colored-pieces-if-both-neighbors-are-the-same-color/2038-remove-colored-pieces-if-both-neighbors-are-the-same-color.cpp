class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        for(int i=0;i<colors.length();i++){
            int temp_count = 0;
            if(colors[i]=='A'){
            while(colors[i]=='A'){
                temp_count++;
                i++;
            }
                i--;
                if(temp_count-2>0){
                    a += (temp_count-2);
                }
            }else{
                while(colors[i]=='B'){
                temp_count++;
                i++;
            }
                i--;
                if(temp_count-2>0){
                    b += (temp_count-2);
                }
                
            }
        }
        if(a>b){
            return true;
        }else{
            return false;
        }
        
  }
};