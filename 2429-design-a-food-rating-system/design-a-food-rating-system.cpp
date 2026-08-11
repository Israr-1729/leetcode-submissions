class FoodRatings {
public:

    unordered_map<string, map<int, set<string>>> items; //Cuisine -> Rating -> Food
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i<cuisines.size(); i++)
        {
            const string &cuisine = cuisines[i];
            //For a particular cuisine, at rating = ratings[i], a list of food exists.
            items[cuisine][ratings[i]].insert(foods[i]);

            foodToCuisine[foods[i]] = cuisine;
            foodToRating[foods[i]] = ratings[i];
        }

    }
    
    void changeRating(string food, int newRating) {
        const string &cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        items[cuisine][oldRating].erase(food);

        if(items[cuisine][oldRating].empty())
        items[cuisine].erase(oldRating);

        foodToRating[food] = newRating;

        items[cuisine][newRating].insert(food);
    
    }
    
    string highestRated(string cuisine) {
        const auto &ratingToFood = items[cuisine];
        const auto &highestRatedFoods = ratingToFood.rbegin() -> second;
        string result = *highestRatedFoods.begin();

        return result;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */