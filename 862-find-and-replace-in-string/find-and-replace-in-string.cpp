class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string result = s;
        int track = 0;

vector<int> order(indices.size());

iota(order.begin(), order.end(), 0);

sort(order.begin(), order.end(), [&](int a, int b) {
    return indices[a] < indices[b];
});
for (int j : order)
{
    int idx = indices[j];

    if (s.substr(idx, sources[j].size()) == sources[j])
    {
        result.replace(idx + track, sources[j].size(), targets[j]);

        track += targets[j].size() - sources[j].size();
    }
}
        return result;
    }
};