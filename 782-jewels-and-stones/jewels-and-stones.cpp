class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelSize = jewels.size();
        int stoneSize = stones.size();
        int counter = 0;

        for(int i = 0; i<stoneSize; i++)
        {
            for(int j = 0; j<jewelSize; j++)
            {
                if (stones[i]==jewels[j])
                {
                counter++;
                break;
                }
            }
        }
        return counter;
    }
};