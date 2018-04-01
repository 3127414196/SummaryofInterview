class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = col - 1;
        int high = 0;
        int btm = rows - 1;

        vector <int> result;

        int i = 0;
        while(left <= right && high <= btm)
        {
            for (i = left; i <= right; i++)
                result.push_back(matrix[high][i]);
            if (high < btm)                         //[[1,2,3,4]]
                for (i = high + 1; i <= btm; i++)
                    result.push_back(matrix[i][right]);
            if ((left < right) && (high < btm))
                for (i = right - 1; i >= left; i--)
                    result.push_back(matrix[btm][i]);
            if ((btm - 1 > high) && (left < right)) //[[1][2][3][4]]
                for (i = btm - 1; i > high; i--)
                    result.push_back(matrix[i][left]);
            left++;
            right--;
            high++;
            btm--;
        }

        return result;
    }
};
