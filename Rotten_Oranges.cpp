class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int fresh_oranges = 0, count = 0, days = 0, m = grid.size(), n=grid[0].size();
        int R[] = {-1,+1,0,0};
        int C[] = {0,0,-1,+1};
        queue<pair<int,int>>rotten_oranges;
        
        //count total oranges and push rotten oranges to the queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)fresh_oranges++;
                if(grid[i][j]==2)rotten_oranges.push({i,j});
            }
        }
        
        while(!rotten_oranges.empty()){
            int SIZE = rotten_oranges.size();
            for(int i=0;i<SIZE;i++){
                auto rotten_orange_position = rotten_oranges.front();
                rotten_oranges.pop();
                for(int dir=0;dir<4;dir++){
                    int next_x = rotten_orange_position.first + R[dir];
                    int next_y = rotten_orange_position.second + C[dir];
                    if(next_x<0 || next_y<0 || next_x>=m || next_y>=n || grid[next_x][next_y]!=1)continue;
                    rotten_oranges.push({next_x,next_y});
                    grid[next_x][next_y]=2;
                    fresh_oranges--;
                }//end for dir
            }//end for i
            if(!rotten_oranges.empty())days++;
        }//end while
        return (fresh_oranges == 0)?days:-1;
    }
};