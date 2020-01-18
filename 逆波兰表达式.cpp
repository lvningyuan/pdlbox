class Solution
{
    stack<int> s;
public:
    int evalRPN(vector<string> &tokens)
    {
        for (auto i : tokens)
            if (i.size() > 1 || i >= "0") s.push(stoi(i));
            else
            {
                int temp = s.top(); s.pop();
                if (i == "+")       s.top() += temp;
                else if (i == "-")  s.top() -= temp;
                else if (i == "*")  s.top() *= temp;
                else                s.top() /= temp;
            }
        return s.top();
    }
};