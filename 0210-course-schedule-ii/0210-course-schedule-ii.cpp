class Solution {
public:

    bool isCycleDFS(int src, vector<bool> &vis,  vector<bool> &recPath,vector<vector<int>>& edges ){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][1];
            int v=edges[i][0];
            if(src==u){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,edges)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    void topoOrder(int src,stack<int> &s,vector<bool> &vis,vector<vector<int>>& edges){
        vis[src]=true;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][1];
            int v=edges[i][0];
            if(src==u){
                if(!vis[v]){
                    topoOrder(v,s,vis,edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,edges)){
                    return ans;
                }
            }
        }
        vis.assign(n,false);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoOrder(i,s,vis,edges);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};