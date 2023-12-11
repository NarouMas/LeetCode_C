#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1, threshold = arr.size() / 4;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] != arr[i - 1])
                count = 1;
            else
            {
                count++;
                if(count > threshold)
                    return arr[i];
            }
        }
        return arr[0];
    }
};