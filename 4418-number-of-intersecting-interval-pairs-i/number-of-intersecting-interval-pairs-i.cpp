class Solution {
public:
    string parser(int i, int j)
    {
        string ans = to_string(i);
        ans += '#';
        ans += to_string(j);
        ans += '$';

        return ans;
    }
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        unordered_set<string> intersectingIndices;
        unordered_map<int, vector<int>> numberToInterval;

        for(int i = 0; i < intervals.size(); i++)
        {
            const vector<int> &interval = intervals[i];
            for(int j = interval[0]; j <= interval[1]; j++)
            {
                numberToInterval[j].push_back(i);
            }
        }

        for(auto &a : numberToInterval)
        {
            const vector<int> &isIn = a.second;
            if(isIn.size() < 2)
            continue;

            for(int i = 0; i < isIn.size(); i++)
            {
                for(int j = i+1; j < isIn.size(); j++)
                {
                    intersectingIndices.insert(parser(isIn[i], isIn[j]));
                }
            }
        }
        return intersectingIndices.size();
    }
};