
multiset 解法：

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s1(nums1.begin(), nums1.end());
        multiset<int> s2;
        vector <int> v;
        for(auto e : nums2)
        {
            auto it = s1.find(e);
            if(it != s1.end())
            {
               s1.erase(it);
               v.push_back(e);
            }
        }
        return v;
    }
};




unordered_map. 收支思想
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int, int> m;
        for(auto e:nums1)
        {
            ++m[e];
        }
        for(auto e: nums2)
        {
            if(m[e] > 0)
            {
                v.push_back(e);
                --m[e];
            }
        }
        return v;
    }
};