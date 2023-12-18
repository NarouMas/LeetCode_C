#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++)
        {
            fr[foods[i]] = ratings[i];
            fc[foods[i]] = cuisines[i];
            cr[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = fc[food];
        cr[cuisine].erase({-fr[food], food});
        cr[cuisine].insert({-newRating, food});
        fr[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cr[cuisine].begin()->second;
    }
private:
    unordered_map<string, int> fr;
    unordered_map<string, string> fc;
    unordered_map<string, set<pair<int, string>>> cr;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */