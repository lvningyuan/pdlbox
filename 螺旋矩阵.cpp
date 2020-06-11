

//3*3 以下可以DFS做


//下面这种思路做法最好， 但是仔细体会， 它其实类似于DFS 但是又有很大不同， 类似于 DFS + BFS。的组合思想



class Solution {
private:
    int edge; // 总个数
    int a;
    vector<vector<bool>> memo;
    vector<vector<int>> ret;
    int next[4][2] ={{0,1}, {1,0}, {0,-1}, {-1,0}};

private:
    bool InArea(int x, int y){
        return x>=0 && x<a && y>=0 && y<a;
    }

private:
    void go(int index, int x, int y, int d){
        while(index<=edge){
            memo[x][y] = true;
            ret[x][y] = index;
            ++index;
            
            int tx = x + next[d][0];
            int ty = y + next[d][1];
            
            if(!InArea(tx,ty)|| memo[tx][ty] ){
                d =(d+1) % 4;
                tx = x + next[d][0];
                ty = y + next[d][1];
            }
            x = tx;
            y = ty;
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        memo=vector<vector<bool>>(n,vector<bool>(n,false));
        ret=vector<vector<int>>(n, vector<int>(n, 0));
        edge = n * n;
        a  = n;
        go(1, 0, 0, 0);     
        return ret;
    }
};