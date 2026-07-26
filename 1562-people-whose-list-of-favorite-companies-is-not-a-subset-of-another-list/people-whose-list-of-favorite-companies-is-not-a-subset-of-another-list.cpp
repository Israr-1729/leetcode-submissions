class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<unordered_set<string>>copy;

        for(auto &v : favoriteCompanies)
        {
            unordered_set<string> thisFavorite;
            for(string &s : v)
            {
                thisFavorite.insert(s);
            }
            copy.push_back(thisFavorite);
        }

        vector<int> result;
        for(int i = 0; i<favoriteCompanies.size(); i++)
        {
            bool isSubset = false;
            for(int j = 0; j<favoriteCompanies.size(); j++)
            {
                if(i==j)
                continue;
                bool isSubsetOfThisJ = true;
                for(string &s : favoriteCompanies[i])
                {
                    if(!copy[j].contains(s))
                    {
                        isSubsetOfThisJ = false;
                        break;
                    }
                }

                if(isSubsetOfThisJ)
                {
                    isSubset = true;
                    break;
                }
            }
            if(!isSubset)
            result.push_back(i);
        }
        return result;
    }
};