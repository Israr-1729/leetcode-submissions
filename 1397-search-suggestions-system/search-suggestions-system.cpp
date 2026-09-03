class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        string typed = "";
        for(int i = 0; i < searchWord.size(); i++)
        {
            typed += searchWord[i];
            vector<string> recommendations;
            for(const string &s : products)
            {
                if(s.starts_with(typed))
                recommendations.push_back(s);

                if(recommendations.size() == 3)
                break;
            }
            result.push_back(recommendations);
        }
    return result;
    }
};