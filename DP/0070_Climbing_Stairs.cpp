#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n){
        int arr[45];
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2; i <= n; i++)
            arr[i] = arr[i - 1] + arr[i - 2];
        return arr[n];
    }
};