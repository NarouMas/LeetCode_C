#include<iostream>
#include<unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
public:
    unordered_set<int> set;
    RandomizedSet() {
        set.clear();
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(set.count(val))
            return false;
        else
            set.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(set.count(val))
        {
            set.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        int i = rand() % set.size();
        unordered_set<int>::iterator it = set.begin();
        for(int j = 0; j < i; j++)
            it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */