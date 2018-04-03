class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
            return 0;
        return GetNumberOfKDivide(data, k, 0, data.size() - 1);
    }
    int GetNumberOfKDivide(vector<int> data, int k, int left, int right)
    {
        if (left == right)
        {
            if (data[left] == k)
                return 1;
            else
                return 0;
        }

        int mid = (left + right) / 2;
        int count = 0;
        if (data[mid] >= k)
            count = GetNumberOfKDivide(data, k, left, mid);
        if (data[mid + 1] <= k)
        count = count + GetNumberOfKDivide(data, k, mid + 1, right);
        return count;
    }
};
