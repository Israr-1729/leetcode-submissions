class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int numberOfDistinctCandies = 0;
        unordered_set<int> isThere;

        for(int a : candyType)
        {
            if(isThere.contains(a))
            continue;

            else
            {
                numberOfDistinctCandies++;
                isThere.insert(a);
            }
        }

        return numberOfDistinctCandies<candyType.size()/2 ? numberOfDistinctCandies : candyType.size()/2;
        
    }
};