#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int, int> r, c;
        int res = 0;
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                if(mat[i][j] == 1)
                        r[i]++, c[j]++;
        
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                if(mat[i][j] == 1 && r[i] == 1 && c[j] == 1)
                        res++;
                
        return res;
    }
};