class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        map<int,vector<int>>m;
        int inserted[101];
        for(int i=0;i<101;i++){
            inserted[i] = 0;
        }
        
        queue<int>ins;
        ins.push(id);
        
        while(!ins.empty()){
            int x = ins.front();
            ins.pop();
            inserted[x] = 1;
            for(int a:friends[x]){
                if(!inserted[a]){
                    m[x].push_back(a);
                    m[a].push_back(x);
                    ins.push(a);
                    inserted[a] = 1;
                }
            }
        }
        queue<pair<int,int>>q;
        int vis[101];
        
        for(int i=0;i<101;i++){
            vis[i]=0;
        }
        q.push({id,0});
        vis[id] = 1;
        vector<int>levelele;
        while(!q.empty()){
            pair<int,int>a = q.front();
            vis[a.first] = 1;
            if(a.second==level){
                levelele.push_back(a.first);
            }
            q.pop();
            for(int x:m[a.first]){
                if(!vis[x]){
                    q.push({x,a.second+1});
                }
            }
        }
        map<string,int>out;
        set<pair<int,string>>abc;
        for(int i=0;i<levelele.size();i++){
            for(int j=0;j<watchedVideos[levelele[i]].size();j++){
                out[watchedVideos[levelele[i]][j]]++;
            }
        }
        for(int i=0;i<levelele.size();i++){
            for(int j=0;j<watchedVideos[levelele[i]].size();j++){
                abc.insert({out[watchedVideos[levelele[i]][j]],watchedVideos[levelele[i]][j]});
            }
        }
        vector<string>answer;
        for(pair<int,string> x:abc){
            answer.push_back(x.second);
        }
        for(int i=0;i<answer.size();i++){
            if(answer[i]=="abcsi"){
                cout<<out[answer[i]]<<endl;
            }
        }
        cout<<out[answer[0]]<<" "<<out[answer[1]];
      
        return answer;
    }
};