#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        foo(arr, "", 0, result);
        return result;
    }
    void foo(vector<string>& arr, string path, int index, int& result)
    {
        vector<bool> map(26, 0);
        bool unique = true;
        for(int i = 0; i < path.size(); i++)
        {
            if(map[path[i] - 'a'])
            {
                unique = false;
                break;
            }
            map[path[i] - 'a'] = true;
        }
        if(unique)
            result = max(int(path.size()), result);
        if(index == arr.size() || !unique)
            return;
        for(int i = index; i < arr.size(); i++)
            foo(arr, path + arr[i], i + 1, result);
    }
};