class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        
        for(int i=0;i<tasks.size();i++){
            int x = m[tasks[i]];
            
            if(x==1){
                return -1;
            }
            if((x-3)%2==0 ||(x-2)%3==0 ||x%3==0 ||x%2==0){
                continue;
            }
            else{
                cout<<x<<endl;
                return -1;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<tasks.size();i++){
            if(m[tasks[i]]>0){
                
                int num = m[tasks[i]];
                
                int a1 = num/3;
                
                if(num-(a1*3)!=1){
                    if(num-(a1*3)==0){
                        cnt+=a1;
                    }else{
                        cnt+=a1+1;
                    }
                }else{
                    cnt+=a1+1;
                }
                m[tasks[i]]=0;
            }
        }
        return cnt;
    }
};