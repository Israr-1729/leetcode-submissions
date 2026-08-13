class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                              vector<string>& ids,
                                              vector<int>& views) {
        unordered_map<string, long long> creatorToViews;
        unordered_map<string, int> creatorToMostPopularVideoViews;
        unordered_map<string, string> creatorToMostPopularVideo;

        for (int i = 0; i < creators.size(); i++) {
            creatorToViews[creators[i]] += views[i];

            if (!creatorToMostPopularVideoViews.contains(creators[i]) ||
                views[i] > creatorToMostPopularVideoViews[creators[i]] ||
                (views[i] == creatorToMostPopularVideoViews[creators[i]] &&
                 ids[i] < creatorToMostPopularVideo[creators[i]])) {
                    
                creatorToMostPopularVideoViews[creators[i]] = views[i];
                creatorToMostPopularVideo[creators[i]] = ids[i];
            }

        }

        long long maxViews = INT_MIN;

        for (auto& a : creatorToViews) {
            maxViews = max(maxViews, a.second);
        }

        vector<string> creatorsWithMaxViews;

        for (auto& a : creatorToViews) {
            if (a.second == maxViews)
                creatorsWithMaxViews.push_back(a.first);
        }

        vector<vector<string>> result;

        for (string& s : creatorsWithMaxViews) {
            result.push_back({s, creatorToMostPopularVideo[s]});
        }

        cout << creatorToMostPopularVideoViews[creatorsWithMaxViews[0]];

        return result;
    }
};