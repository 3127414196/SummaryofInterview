class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int column = array.size();
        int rows = array[0].size();
        if (column == 0)
            return false;
        int i = column - 1;
        int j = 0;
        while (i >= 0 && j < rows)  //注意这里循环终止条件，是当遍历完一行或者是一列结束
        {
            if (array[i][j] == target)
                return true;
            else if (array[i][j] > target)
                i--;
            else if (array[i][j] < target)
                j++;
        }
        return false;
    }
};
