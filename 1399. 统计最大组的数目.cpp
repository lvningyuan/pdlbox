class Solution {
public:
    int countLargestGroup(int n) {
        int hash[37] = {0}, res = 0, sum = 0, cnt = 0;
        for (int i = 1; i <= n; i ++) {
            res = i, sum = 0;
            while (res) sum = sum + res % 10, res = res / 10;
            hash[sum] ++;
        }
        //降序排
        sort(hash, hash + 37, greater<int>());
        for (int i = 0; i < 37; i ++) {
            if (hash[i] == hash[0]) cnt ++;
            else break;
        }
        return cnt;
    }
};