class Solution {
public:
    vector<vector <int> > subsets(vector<int>& nums) {
        vector<vector<int>> res(1);//��ά������1���յ�����
        for(int i =0; i< nums.size(); ++i)//����Ŀ������
        {
            int size =  res.size();//��¼���е�res�����С
            for(int j=0; j<size; ++j)//�����е������Ͻ���׷�ӣ��γ��µ���ϣ�����res����
            {
                vector<int> tmp = res[j];//ÿ�˽�������res����ĵ�һ��ֱ��ĩβ����׷��
                tmp.push_back(nums[i]);//��Ŀ��?��Ԫ�����׷�ӣ��γ������
                res.push_back(tmp);//����Ϸ���res����
            }
        }
        return res;
    }
};