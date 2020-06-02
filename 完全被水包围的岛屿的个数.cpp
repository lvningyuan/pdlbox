class Solution {
private: 
    int ret =0;
    int l1,l2;
    vector<vector<bool>>memo;
    int next[4][2] ={{-1,0}, {0,1}, {1,0}, {0, -1}};
private:   
    bool inArea(int a, int b){
        //完全被包围意味着 不能在边界， 那么暂时不判断边界是否是合理
        return a>=0 && a <l1 && b>=0 && b<l2;
    }
private:
    bool touchEdge(int a, int b){
        return a <=0 ||a >=l1-1 || b <=0 ||b >=l2-1;
    }

private:
    void dfs(vector<vector<int>>& grid, int x, int y, bool& flag){
         //是否触碰边界
        if(touchEdge(x,y)) {
            flag = true;
            return ;
        }
        memo[x][y] = true;//访问过了
        for(int i=0; i<4; ++i){
            int newx = x + next[i][0];
            int newy = y + next[i][1];
            //不再这里判断 flag第二次值 是为了保证生深度优先搜索走到底
            if(inArea(newx, newy) && !grid[newx][newy] && !memo[newx][newy]){
                dfs(grid, newx, newy, flag);
        }
    }
}

public:
    int closedIsland(vector<vector<int>>& grid) {
        l1 = grid.size();
        if(l1==0) return 0;
        l2 = grid[0].size(); 
        memo=vector<vector<bool>>(l1,vector<bool>(l2,false)); 
        for(int i=0; i<l1; ++i)
            for(int j=0; j<l2; ++j)
            if(!grid[i][j] && !memo[i][j]){
                bool flag = false;
                dfs(grid, i, j, flag);
                if(!flag) 
                   ++ret;
            }
        return ret;
    }   
};