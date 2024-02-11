class Solution {
public:
    int dp[71][71][71];
    int help(vector<vector<int>> &grid,int r1,int c1,int c2){
        int r2 = r1;
        if(r1 >= grid.size() || r1 < 0 || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()){
            return 0;
        }
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        if(r1 == grid.size() - 1){
            if(c1 == c2) return grid[r1][c1];
            else grid[r1][c1] + grid[r1][c2];
        }
        int cherry = 0;
        if(c1 == c2){
            cherry += grid[r1][c1];
        }else{
            cherry += grid[r1][c1] + grid[r1][c2];
        }
        int maxcherry = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                maxcherry=max(maxcherry,help(grid,r1+1,c1+i,c2+j));
            }
        }
        cherry += maxcherry;
        return dp[r1][c1][c2] = cherry; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return help(grid,0,0,n - 1);
    }
};
