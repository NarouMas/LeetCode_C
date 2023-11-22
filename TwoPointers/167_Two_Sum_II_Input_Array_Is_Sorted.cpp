#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> res(2, 0);
        while(i < j)
        {
            if(numbers[i] + numbers[j] < target)
                i++;
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
            {
                res[0] = i + 1;
                res[1] = j + 1;
                return res;
            }
        }
        return res;
    }
};