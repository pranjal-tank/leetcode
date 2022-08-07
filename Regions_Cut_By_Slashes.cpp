class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &g,vector<bool> &vis){
        vis[node]=true;
        for(auto child: g[node]){
            if(!vis[child])
                dfs(child,g,vis);
        }
        return;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int ans=0;
        int n=grid.size();
        vector<vector<int>> g(2*n*n);
        int x_dir[2]={0,1};
        int y_dir[2]={1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==' '){
                    g[(i*2)+(2*n*j)].push_back((i*2+1)+(2*n*j));
                    g[(i*2+1)+(2*n*j)].push_back((i*2)+(2*n*j));
                }
                for(int k=0;k<2;k++){
                    int x=i+x_dir[k];
                    int y=j+y_dir[k];
                    
                    if(x>=0 && x<n && y>=0 && y<n){
                       if(k==0){
                           if(grid[i][j]=='/' && grid[x][y]=='/'){
                               g[(i*2+1)+(2*n*j)].push_back((x*2)+(2*n*y));
                                g[(x*2)+(2*n*y)].push_back((i*2+1)+(2*n*j));
                           }
                           else if(grid[i][j]=='\\' && grid[x][y]=='\\'){
                               g[(i*2)+(2*n*j)].push_back((x*2+1)+(2*n*y));
                                g[(x*2+1)+(2*n*y)].push_back((i*2)+(2*n*j));
                           }
                           else if(grid[i][j]=='/' && grid[x][y]==' '){
                               g[(i*2+1)+(2*n*j)].push_back((x*2+1)+(2*n*y));
                                g[(x*2+1)+(2*n*y)].push_back((i*2+1)+(2*n*j));
                           }
                           else if(grid[i][j]=='\\' && grid[x][y]==' '){
                               g[(i*2)+(2*n*j)].push_back((x*2)+(2*n*y));
                                g[(x*2)+(2*n*y)].push_back((i*2)+(2*n*j));
                           }
                           else if(grid[x][y]==' '){
                                g[(i*2)+(2*n*j)].push_back((x*2)+(2*n*y));
                                g[(x*2)+(2*n*y)].push_back((i*2)+(2*n*j));
                                g[(i*2+1)+(2*n*j)].push_back((x*2+1)+(2*n*y));
                                g[(x*2+1)+(2*n*y)].push_back((i*2+1)+(2*n*j));
                            }
                           else if(grid[x][y]=='\\'){
                                g[(i*2+1)+(2*n*j)].push_back((x*2+1)+(2*n*y));
                                g[(x*2+1)+(2*n*y)].push_back((i*2+1)+(2*n*j));
                            }
                            else if(grid[x][y]=='/'){
                                g[(i*2)+(2*n*j)].push_back((x*2)+(2*n*y));
                                g[(x*2)+(2*n*y)].push_back((i*2)+(2*n*j));
                            }   
                       }
                       else{
                         if(grid[x][y]==' ' || grid[x][y]=='\\' || grid[x][y]=='/'){
                                g[(i*2+1)+(2*n*j)].push_back((x*2)+(2*n*y));
                                g[(x*2)+(2*n*y)].push_back((i*2+1)+(2*n*j));
                         } 
                       }
                    }
                }
            }
        }
        vector<bool> vis(2*n*n,false);
        for(int i=0;i<2*n*n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,g,vis);
            }
        }
        return ans;
    } 
};
