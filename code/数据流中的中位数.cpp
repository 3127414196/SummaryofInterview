class Solution {
public:
    void Insert(int num)
    {
        int size = min.size() + max.size();
        if ((size & 0x1) == 1)    //max
        {
            if (!min.empty() && min[0] < num)
            {
                int temp = min[0];
                min[0] = num;
                push_heap(min.begin(), min.end(), greater<int>());
                num = temp;
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
        else    //min
        {
            if (!max.empty() && max[0] > num)
            {
                int temp = max[0];
                max[0] = num;
                push_heap(max.begin(), max.end(), less<int>());
                num = temp;
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
    }

    double GetMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            return 0;
        if ((size & 0x1) == 1)
            return min[0];
        else
            return (min[0] + max[0]) / 2.0;
    }
private:
    vector<int> min;
    vector<int> max;
};
