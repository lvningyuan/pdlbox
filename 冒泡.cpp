class Solution {
public:

void Swap(int& a, int& b)
{
    int tmp =a;
    a = b;
    b = tmp;
}
int Getmid(vector<int>& v, int begin , int end)
{
    int mid = begin +((end - begin)>>1);
    if(v[begin] > v[mid])
    {
        if(v[mid] > v[end])
            return mid;
        else if(v[begin]  > v[end])
            return end;
        else 
            return begin;  
    } 
    else//begin < mid 
    {   
        if(v[mid] < v[end])
            return mid;
        else if(v[begin] > v[end])
            return begin;
        else
            return end;
    }
}
void QSort(vector<int>& v, int begin ,int end)
{
    if(begin >= end)
    return;
    if (begin +1 == end) //判断三数取中法数够不够
    {
        if(v[begin] > v[end])
            Swap(v[begin], v[end]);

        return ;
    }
    
int keyindex = PartSort(v, begin, end);
PartSort(v,begin, keyindex -1);
PartSort(v, keyindex +1, end);
}

int PartSort(vector<int>& v, int begin, int end)
{
    int mid = Getmid(v, begin, end);
    Swap(v[end], v[mid]);
    int key= end;
    int cur =begin;
    int prev = begin - 1;
    while(cur < end)
    {
        if(v[cur] < v[key] && ++prev != cur)
            Swap(v[cur] ,v[prev]);

            ++cur;   
    }
    Swap(v[++prev] ,v[key]);
    return prev;
}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        QSort(nums, 0 ,n-1);
        return nums;
    }
};