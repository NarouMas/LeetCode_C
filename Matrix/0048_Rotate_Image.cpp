#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() / 2; i++)
        {
            for(int j = i; j < matrix.size() - i - 1; j++)
            {
                int ax = j, ay = i, bx = matrix.size() - 1 - i, by = j, cx = matrix.size() - 1 - j, cy = matrix.size() - 1 - i, dx = i, dy = matrix.size() - 1 - j;
                swap(matrix[ay][ax], matrix[by][bx]);
                swap(matrix[cy][cx], matrix[dy][dx]);
                swap(matrix[ay][ax], matrix[cy][cx]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> res;
    Solution sol;

    sol.rotate(arr1);
    for(int i = 0; i < arr1.size(); i++)
    {
        for(int j = 0; j < arr1.size(); j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    sol.rotate(arr2);
    for(int i = 0; i < arr2.size(); i++)
    {
        for(int j = 0; j < arr2.size(); j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<"\n";
    }
}