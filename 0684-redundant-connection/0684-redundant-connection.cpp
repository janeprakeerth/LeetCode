class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        map<int,vector<int>>adjList;
        
        int parent[1001];
        int rank[1001];
        for(int i=0;i<1001;i++){
            parent[i] = i;
        }
        for(int i=0;i<edges.size();i++){
            int par_x = findParent(parent,edges[i][0]);
            int par_y = findParent(parent,edges[i][1]);
            
            if(par_x==par_y){
                return {edges[i][0],edges[i][1]};
            }else{
                if(par_x==edges[i][0] && par_y==edges[i][1]){
                      parent[edges[i][1]] = edges[i][0];
                }else if(par_x!=edges[i][0] && par_y==edges[i][1]){
                    parent[edges[i][1]] = par_x;
                }else if(par_x==edges[i][0] && par_y!=edges[i][1]){
                    parent[edges[i][0]] = par_y;
                }else{
                    parent[par_y] = par_x;
                }
            }
        }
        for(int i=0;i<1001;i++){
            cout<<parent[i]<<" ";
        }
        return {0,0};
    }
    
    int findParent(int arr[],int n){
        if(arr[n]==n){
            return n;
        }
        int x = findParent(arr,arr[n]);
        return x;
    }
};