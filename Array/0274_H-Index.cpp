#include<iostream>
#include<algorithm>
using namespace std;

bool mycompare(int a, int b) {
    return a > b;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), mycompare);
        for(int i = 0; i < citations.size(); i++)
        {
            if(i + 1 >= citations[i])
                return (citations[i] > i) ? citations[i] : i;
        }
        return citations.size();
    }
};  