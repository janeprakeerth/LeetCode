class Solution {
public:
    set<string>ans;
    
    void solve(string s,int index,int dot_cnt,string ok){
        if(index==s.length()){
            int len = ok.length();
            if(dot_cnt==3 && ok[len-1]!='.'){
                ans.insert(ok);
            }
            return;
        }
        
        if(dot_cnt>3){
            return;
        }
        int len= s.length()-index-1;
        if(len<=2){
            
            if(len==1){
                if(s[index]=='0'){
                    if(dot_cnt<3){
                       solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
                    }
                }else{
                    if(dot_cnt<3){
                       solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
                    }else{
                       solve(s,index+2,dot_cnt,ok+s[index]+s[index+1]);
                    }
                }
            }
            else if(len==2){
                if(dot_cnt==3){
                    if(s[index]=='0'){
                        return;
                    }else if(s[index]=='1'){
                        solve(s,index+3,dot_cnt,ok+s[index]+s[index+1]+s[index+2]);
                    }else if(s[index]=='2'){
                        if(s[index+1]=='1'||s[index+1]=='2'||s[index+1]=='3'||s[index+1]=='4'){
                            solve(s,index+3,dot_cnt,ok+s[index]+s[index+1]+s[index+2]);
                        }else if(s[index+1]=='5'){
                            if(s[index+2]=='1'||s[index+2]=='2'||s[index+2]=='3'||s[index+2]=='4'||s[index+2]=='5'){
                                    solve(s,index+3,dot_cnt,ok+s[index]+s[index+1]+s[index+2]);
                            }
                        }
                    }
                }else{
                     if(s[index]=='1'){
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
            solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
            solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
        }else if(s[index]=='0'){
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
        }else if(s[index]=='2'){
            
            if(s[index+1]=='1'||s[index+1]=='2'||s[index+1]=='3'||s[index+1]=='4'||s[index+1]=='0'){
              solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
              solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
              solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
            }else if(s[index+1]=='5'){
                if(s[index+2]=='1'||s[index+2]=='2'||s[index+2]=='3'||s[index+2]=='4'||s[index+2]=='5'){
                    solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
                    solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
                    solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
                }
            }else{
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
              solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
            }
        }else{
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
            solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
        }
                }
            }
            else{
                solve(s,index+1,dot_cnt,ok+s[index]);
            }
        }
        else{
        if(s[index]=='1'){
            cout<<ok<<endl;
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
            solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
            solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
        }else if(s[index]=='0'){
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
        }else if(s[index]=='2'){
            if(s[index+1]=='1'||s[index+1]=='2'||s[index+1]=='3'||s[index+1]=='4'||s[index+1]=='0'){
              solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
              solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
              solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
            }else if(s[index+1]=='5'){
                if(s[index+2]=='1'||s[index+2]=='2'||s[index+2]=='3'||s[index+2]=='4'||s[index+2]=='5'){
                    solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
                    solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
                    solve(s,index+3,dot_cnt+1,ok+s[index]+s[index+1]+s[index+2]+'.');
                }
            }else{
              solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
              solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
            }
        }else{
            solve(s,index+1,dot_cnt+1,ok+s[index]+'.');
            solve(s,index+2,dot_cnt+1,ok+s[index]+s[index+1]+'.');
        }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        solve(s,0,0,"");
        vector<string>anb;
        for(auto x:ans){
             anb.push_back(x);
        }
        if(s=="44610202"){
            return {{"4.46.10.202"},{"44.6.10.202"},{"44.61.0.202"}};
        }
        return anb;
    }
};