class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> copy1;
        for(int i = 0; i<list1.size(); i++)
        {
            copy1[list1[i]] = i;
        }

        int minIDX = INT_MAX;
        for(int i = 0; i<list2.size(); i++)
        {
            if(copy1.contains(list2[i]))
            {
                if(minIDX > copy1[list2[i]] + i)
                {
                    minIDX = copy1[list2[i]] + i;
                }
            }
        }

        vector<string> result;
        for(int i = 0; i<list2.size(); i++)
        {
            if(copy1.contains(list2[i]))
            {
                if(copy1[list2[i]] + i == minIDX)
                result.push_back(list2[i]);
            }
        }
        return result;
    }
};