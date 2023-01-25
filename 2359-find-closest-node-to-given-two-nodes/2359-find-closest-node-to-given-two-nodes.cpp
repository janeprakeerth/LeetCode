class Solution {
public:
    
    int count = 0;
    void bfs(vector<int>edges,int ele,vector<int>&dist,vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({ele,0});
        dist[ele] = 0;
        vis[ele] = 1;
        while(!q.empty()){
            // q.pop();
            auto x = q.front();
            q.pop();
            int dis =x.second;
            int num = x.first;
            vis[num] = 1;
            dist[num] = dis;
            if(edges[num]!=-1){
            
            if(!vis[edges[num]]){
                q.push({edges[num],dis+1});
            }
            }
        }
    }
//      void dfs2(map<int,vector<int>>m,int dist,int ele,vector<int>&dist2,vector<int>&vis2){
//         dist2[ele] = dist;
//         vis2[ele]=1;
         
//             for(int i=0;i<m[ele].size();i++){
//                 if(!vis2[m[ele][i]]){
//                 dfs2(m,dist+1,m[ele][i],dist2,vis2);
//                 }
//             }
//     }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,vector<int>>m;
       
        vector<int>dist1(edges.size(),-1);
        vector<int>dist2(edges.size(),-1);
        vector<int>vis1(edges.size(),0);
        vector<int>vis2(edges.size(),0);
        bfs(edges,node1,dist1,vis1); 
        bfs(edges,node2,dist2,vis2);
        
        
        int dist = INT_MAX;
        int ans = INT_MIN;
        dist1[node1] = 0;
        dist2[node2] = 0;
        // for(int i=0;i<edges.size();i++){
        //     cout<<dist1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<edges.size();i++){
        //     cout<<dist2[i]<<" ";
        // }
        for(int i=0;i<edges.size();i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int x = max(dist1[i],dist2[i]);
                if(dist>x){
                    dist = x;
                    ans = i;
                }
            }
        }
        if(ans==INT_MIN){
            return -1;
        }
        return ans;
    }
};