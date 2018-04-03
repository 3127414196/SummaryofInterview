class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if (sum == 0 || sum == 1 || sum == 2)
            return result;

        int begin = 1;
        int end = 2;
        int mid = (1 + sum) / 2;
        int cursum = 3;

        while (begin < mid) {
            while (cursum < sum) {
                end++;
                cursum += end;
            }
            while (cursum > sum) {
                cursum-=begin;
                begin++;
            }
            if (cursum == sum)
            {
                vector<int> temp;
                for (int i = begin; i <= end; i++)
                    temp.push_back(i);
                result.push_back(temp);
            }
            end++;
            cursum = cursum + end - begin;
            begin++;
        }
        return result;
    }
};
