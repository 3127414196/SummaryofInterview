class Solution {
public:
    int InversePairs(vector<int> data) {
        int datalenght = data.size();
        if (datalenght == 0)
            return 0;
        if (datalenght == 1)
            return 1;
        vector<int> copy(data);
        return countInversePairs(data, copy, 0, datalenght - 1);
    }
    int countInversePairs(vector<int> data, vector<int> copy, int left, int right)
    {
        if (left == right)
            return 0;
        int mid = (left + right) / 2;
        int count = countInversePairs(data, copy, left, mid);
        count = count + countInversePairs(data, copy, mid + 1, right);
        count = count + merge(data, copy, left, mid, right);
        return count % 1000000007;
    }
    int merge(vector<int> data, vector<int> copy, int left, int mid, int right)
    {
        int pmid = mid;
        int pright = right;
        int indexCopy = right;
        long cnt = 0;

        while(pmid >= left && pright >= mid + 1)
        {
            if (data[pmid] > data[pright])
            {
                copy[indexCopy--] = data[pmid--];
                cnt += pright - mid;
            }
            else
            {
                copy[indexCopy--] = data[pright--];
            }
        }

        while(pmid >= left)
        {
            copy[indexCopy--] = data[pmid--];
        }
        while(pright >= mid + 1)
        {
            copy[indexCopy--] = data[pright--];
        }

        return cnt % 1000000007;
    }
};
