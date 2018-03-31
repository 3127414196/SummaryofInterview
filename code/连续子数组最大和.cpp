class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0)
            return 0;
        int endingheresum = array[0];   //need initial value
        int maxsum = array[0];
        int length = array.size();
        int i = 1;
        while(i < length)
        {
            endingheresum += array[i];
            if (endingheresum > maxsum)
                maxsum = endingheresum;
            if (endingheresum < 0)
                endingheresum = 0;
            i++;
        }
        return maxsum;
    }
};
