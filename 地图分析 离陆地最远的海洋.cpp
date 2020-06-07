
你现在手里有一份大小为 N x N 的「地图」（网格） grid，上面的每个「区域」（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。

如果我们的地图上只有陆地或者海洋，请返回 -1。


class Solution {
private:
    int l1, l2;
    static constexpr int MAX_N = 100 + 5;//每次需要刷新memo
    int memo[MAX_N][MAX_N];

    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    struct coordernary{
        int x;
        int y;
        int step;
    };

private:
    bool inArea(int x, int y){
        return x>=0 && x<l1 && y>=0 && y<l2;
    }

//深搜不不是很好搞step
int BFS(vector<vector<int>>& grid, int x, int y){
    memset(memo, 0, sizeof memo);// 重置memo非常重要
                        //因为别的海洋也可能会经过已经走过的海洋
    memo[x][y] = true;
    queue<coordernary> q;
    q.push( {x,y,0} );

    while(!q.empty()){
        auto f = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int newx = f.x + next[i][0];
            int newy = f.y + next[i][1];
            if(inArea(newx, newy) && !memo[newx][newy]){
                q.push( {newx, newy, f.step+1} );
                memo[newx][newy] = true;
                
                if(grid[newx][newy] == 1)
                    return f.step + 1; 
            }
        }
    }
    return -1;//说明没遇到陆地
}

public:
    int maxDistance(vector<vector<int>>& grid) {
        l1 = grid.size();
        if(l1 == 0) return -1;
        l2 = grid[0].size();

    //memo=vector<vector<bool>>(l1,vector<bool>(l2,false));
        int ret = -1;
        for(int i=0; i<l1; ++i)
        for(int j=0; j<l2; ++j)
        if(!grid[i][j]) // 从海洋开始广搜
            ret = max(ret, BFS(grid, i, j));
        
        return ret;
    }
};