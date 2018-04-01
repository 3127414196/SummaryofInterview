class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty() && popV.empty())
            return true;
        if (pushV.size() != popV.size())    //attention
            return false;

        stack <int> pushline;

        int length = pushV.size();
        int pushVi = 0, popVj = 0;

        while ((pushVi < length) && (popVj < length))
        {
            if (pushV[pushVi] != popV[popVj])
            {
                if (pushline.empty() || (pushline.top() != popV[popVj]))
                {
                    pushline.push(pushV[pushVi]);
                    pushVi++;
                }
                else
                {
                    pushline.pop();
                    popVj++;
                }
            }
            else
            {
                pushVi++;
                popVj++;
            }
        }

        while (!pushline.empty() && popVj < length)
        {
            if (pushline.top() != popV[popVj])
                return false;
            pushline.pop();
            popVj++;
        }

        return true;
    }
};
