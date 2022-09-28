class Solution {
public:
    string reformatNumber(string number) {
        string c;
        for(int i=0;i<number.size();i++){
            if(number[i]!='-' && number[i]!=' '){
                c+=number[i];
            }
        }
        string x;
        int count = 0;
        int n = 3;
        if(c.size()==4){
            for(int i=0;i<c.size();i++){
                if(count!=2){
                    x+=c[i];
                    count++;
                }else if(count==2){
                    x+='-';
                    count = 0;
                    i--;
                }
            }
            return x;
        }
        for(int i=0;i<c.size();i++){
            if(count!=n){
                x+=c[i];
                count++;
            }
            else if(count==n){
                if(c.size()-i==4){
                    n=2;
                    cout<<"ok"<<" "<<c[i]<<endl;
                }
                x+='-';
                count = 0;
                i--;
            }
            
        }
        
        return x;
    }
};