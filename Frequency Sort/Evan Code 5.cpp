#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        vector<int> frequencies;
        vector<int> result;
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;
        int offset = 0;

        // find min and max values in the input array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minValue)
            {
                minValue = nums[i];
            }

            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
            }
        }

        // initialize the frequencies array, which will have a length of maxValue - minValue + 1
        for (int i = 0; i < (maxValue - minValue + 1); i++)
        {
            frequencies.push_back(0);
        }

        // calculate offset, the indexes in the frequencies vector represent the values in the nums vector, but the numbers could be negative so we need an offset
        // this offset will be added to the values in the frequencies vector
        offset = 0 - minValue;

        // build the frequencies vector
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            int idx = val + offset;

            frequencies[idx]++;
        }

        // find min and max frequencies in the input array
        for (int i = 0; i < frequencies.size(); i++)
        {
            if (frequencies[i] < minFreq)
            {
                minFreq = frequencies[i];
            }

            if (frequencies[i] > maxFreq)
            {
                maxFreq = frequencies[i];
            }
        }

        // loop through the range of minFreq to maxFreq
        int f = minFreq;
        while (f <= maxFreq)
        {
            // find the indexes for everything with this frequency
            // these indexes match the values in the nums vector
            vector<int> indexesForThisFreq;

            for (int i = 0; i < frequencies.size(); i++)
            {
                if (frequencies[i] == f)
                {
                    indexesForThisFreq.push_back(i);
                }
            }

            // sort indexesForThisFreq in decreasing order
            sort(indexesForThisFreq.begin(), indexesForThisFreq.end(), greater<int>());

            // build the results
            // indexesForThisFreq contains the values we want (minus the offset), and f is the number of times we want it
            for (int x = 0; x < indexesForThisFreq.size(); x++)
            {
                for (int y = 0; y < f; y++)
                {
                    result.push_back(indexesForThisFreq[x] - offset);
                }
            }

            f++;
        }

        return result;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> input;
    vector<int> output;

    input = { 1,1,2,2,2,3 };
    output = sol.frequencySort(input);

    input = { 2,3,1,3,2 };
    output = sol.frequencySort(input);

    input = { -1,1,-6,4,5,-6,1,4,1 };
    output = sol.frequencySort(input);

    return 0;
}
