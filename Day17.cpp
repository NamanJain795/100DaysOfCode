class FoodRatings {
public:
    unordered_map<string, int> foodRate;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineFood;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();++i){
            foodRate[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisine = foodCuisine[food];
        auto old = cuisineFood[cuisine].find({-foodRate[food], food});
        cuisineFood[cuisine].erase(old);
        foodRate[food] = newRating;
        cuisineFood[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto highest = cuisineFood[cuisine].begin();
        return highest->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */