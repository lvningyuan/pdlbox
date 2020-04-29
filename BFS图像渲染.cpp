 图像渲染
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int color = image[sr][sc];
            if(color == newColor ) return image;

            queue<vector<int>> q;
            q.push({sr,sc});
            image[sr][sc] = newColor;
            int vx[] ={0,0,1,-1}; //右下左上
            int vy[] ={1,-1,0,0};

            while(!q.empty())
            {
                vector<int> pos = q.front();
                q.pop();
                for(int i=0; i<4; ++i)
                {
                    int r = vy[i] + pos[0];
                    int c = vx[i] + pos[1];
                    if(r < 0 || r >= image.size()  ||
                          c < 0 || c >= image[0].size())
                        continue;  //走到边界了

                     //BFS思想，优先走一遍当前所有子问题，子问题的子问题交给子问题再去解决   
                    if(image[r][c] == color)
                    {
                        image[r][c] = newColor;
                        q.push({r,c});
                    }
                }
            }
         return image;
    }
};
