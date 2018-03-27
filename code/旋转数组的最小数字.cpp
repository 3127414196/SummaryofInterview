class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;

        int end = rotateArray.size() - 1;
        int begin = 0;
        int mid = begin;

        while (rotateArray[begin] >= rotateArray[end])
        {
            if ((end - begin) == 1)
            {
                mid = end;
                break;
            }

            mid = (begin + end) / 2;
            if ((rotateArray[begin] == rotateArray[mid])
                && (rotateArray[mid] == rotateArray[end]))
            {
                int minnum = rotateArray[begin];
                mid = begin;
                for (int i = begin + 1; i <= end; i++)
                {
                    if (rotateArray[i] < minnum)
                    {
                        minnum = rotateArray[i];
                        mid = i;
                    }
                }
                break;
            }

            else if (rotateArray[end] >= rotateArray[mid])
            {
                end = mid;
            }
            else
            {
                begin = mid;
            }
        }
        return rotateArray[mid];
	}
};
