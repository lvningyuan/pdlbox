一：  判断与结果
x & (x - 1) 操作会将 2 的幂设置为 0，因此判断是否为 2 的幂是：判断 x & (x - 1) == 0

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n &(n-1)) == 0;
    }
};
```

二：判断x  & (-x)  是不是x    

我们通过 x & (-x) 保留了最右边的 1，并将其他位设置为 0 若 x 为 2 的幂，则它的二进制表示中只包含一个 1，则有 x & (-x) = x。

若 x 不是 2 的幂，则在二进制表示中存在其他 1，因此 x & (-x) != x。

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n &(-n)) == n;
    }
};
```
