class Solution {
public:
    
    void dfs(int room,vector<vector<int>> &rooms,vector<bool> &vis){
        vis[room]=true;
        for(auto key: rooms[room]){
            if(!vis[key])
                dfs(key,rooms,vis);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        for(auto i: vis){
            if(i==false)
                return false;
        }
        return true;
    }
};
