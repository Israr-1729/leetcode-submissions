class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int size = bulbs.size();
        vector<bool> OnOrOff(101);
        for(int a : bulbs)
        {
            OnOrOff[a] = !OnOrOff[a];
        }

        vector<int> result;
        for(int i = 1; i<=100; i++)
        {
            if(OnOrOff[i])
            result.push_back(i);
        }
        return result;
    }
};