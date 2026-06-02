class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        // Land first, then Water
        for(int i = 0; i < landStartTime.size(); i++)
        {
            int currTime = landStartTime[i];
            currTime += landDuration[i];

            for(int j = 0; j < waterStartTime.size(); j++)
            {
                int tempTime = currTime;

                if(tempTime < waterStartTime[j])
                {
                    tempTime = waterStartTime[j];
                }

                tempTime += waterDuration[j];

                ans = min(ans, tempTime);
            }
        }

        // Water first, then Land
        for(int i = 0; i < waterStartTime.size(); i++)
        {
            int currTime = waterStartTime[i];
            currTime += waterDuration[i];

            for(int j = 0; j < landStartTime.size(); j++)
            {
                int tempTime = currTime;

                if(tempTime < landStartTime[j])
                {
                    tempTime = landStartTime[j];
                }

                tempTime += landDuration[j];

                ans = min(ans, tempTime);
            }
        }

        return ans;
    }
};