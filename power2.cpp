һ��  �ж�����
x & (x - 1) �����Ὣ 2 ��������Ϊ 0������ж��Ƿ�Ϊ 2 �����ǣ��ж� x & (x - 1) == 0

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n &(n-1)) == 0;
    }
};
```

�����ж�x  & (-x)  �ǲ���x    

����ͨ�� x & (-x) ���������ұߵ� 1����������λ����Ϊ 0 �� x Ϊ 2 ���ݣ������Ķ����Ʊ�ʾ��ֻ����һ�� 1������ x & (-x) = x��

�� x ���� 2 ���ݣ����ڶ����Ʊ�ʾ�д������� 1����� x & (-x) != x��

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n &(-n)) == n;
    }
};
```
