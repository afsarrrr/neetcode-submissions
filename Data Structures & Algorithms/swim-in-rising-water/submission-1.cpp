class Solution {
public:
    #define pp pair<int,pair<int,int>>
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            int t=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1)return max(grid[i][j],t);
             int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int k=0;k<4;k++){
              int x=i+dx[k];
              int y =j+dy[k];
                if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]){
                pq.push({max(t,grid[x][y]),{x,y}});
                    vis[x][y]=1;
                }
            }
        }
        return -1;
    }
};
