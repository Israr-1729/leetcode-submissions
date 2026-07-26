class Solution {
public:

int nextIndexTimestamp(const vector<vector<int>> &series, int val)
{
    int left = 0;
    int right = series.size() - 1;
    int ans = -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(series[mid][0] > val)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if(ans == -1)
        return 0;

    return series[ans][1];
}

    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int size1 = series1.size(); 
        int size2 = series2.size();
        int largest1 = series1[size1-1][0];
        int largest2 = series2[size2-1][0];

        int smallest1 = series1[0][0];
        int smallest2 = series2[0][0];

        set<int> timestamps;

        unordered_map<int, int> copy1;
        for(auto &a : series1)
        {
            copy1[a[0]] = a[1];
            timestamps.insert(a[0]);
        }

        unordered_map<int, int> copy2;
        for(auto &a : series2)
        {
            copy2[a[0]] = a[1];
            timestamps.insert(a[0]);
        }

        vector<vector<int>> result;

        for(auto &a : timestamps)
        {
            if(copy1.find(a) != copy1.end() && copy2.find(a) != copy2.end())
            {
                result.push_back({a, copy1[a]+copy2[a]});
            }

            else if(copy1.find(a) == copy1.end())
            {
                if(a>largest1)
                result.push_back({a, copy2[a]});

                else if(a<smallest1)
                result.push_back({a, copy2[a]+series1[0][1]});

                else
                result.push_back({a, copy2[a] + nextIndexTimestamp(series1, a)});
            }

            else
            {
                if(a>largest2)
                result.push_back({a, copy1[a]});

                else if(a<smallest2)
                result.push_back({a, copy1[a] + series2[0][1]});

                else
                result.push_back({a, copy1[a] + nextIndexTimestamp(series2, a)});
            }
        }
    return result;
    }
};