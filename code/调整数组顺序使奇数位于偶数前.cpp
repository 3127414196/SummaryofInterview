class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty())
            return;

        vector <int> result;
        for (int i = 0; i < array.size(); i++)
        {
            if ((array[i] & 0x1) == 1)
                result.push_back(array[i]);
        }

        for (int i = 0; i < array.size(); i++)
        {
            if ((array[i] & 0x1) == 0)
                result.push_back(array[i]);
        }

        array.clear();      //attention : result in stack, array = result Can cause memory leaks
        for (int i = 0; i < result.size(); i++)
            array.push_back(result[i]);

        return;
    }
};
