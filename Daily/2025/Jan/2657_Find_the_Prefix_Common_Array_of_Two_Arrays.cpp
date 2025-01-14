#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());
        vector<bool> a(A.size(), false), b(B.size(), false);
        int count = 0;
        for(int i = 0; i < A.size(); i++)
        {
            a[A[i]] = true, b[B[i]] = true;
            if(a[A[i]] && b[A[i]])
                count++;
            if(A[i] != B[i] && a[B[i]] && b[B[i]])
                count++;
            res[i] = count;
        }   
        return res;
    }
};