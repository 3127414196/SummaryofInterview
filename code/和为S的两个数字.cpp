class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> result;

        if (length == 0)
            return result;

        int begin = 0;
        int end = length - 1;
        int cursum = array[begin] + array[end];
        while (begin < end) {
            if (cursum > sum)
            {
                end = end - 1;
                cursum = array[begin] + array[end];
            }
            else if (cursum < sum)
            {
               begin = begin + 1;
               cursum = array[begin] + array[end];
            }
            else if (cursum == sum)
            {
                result.push_back(array[begin]);
                result.push_back(array[end]);
                break;
            }
        }

        return result;
    }
};
