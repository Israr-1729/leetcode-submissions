class Solution {
public:
    vector<long long> cubes;

    void fillCubes()
    {
        for(long long i = 1; i <= 1000; i++)
            cubes.push_back(i * i * i);
    }

    vector<int> findGoodIntegers(int n)
    {
        fillCubes();

        unordered_map<long long, int> freq;

        for(int i = 0; i < cubes.size(); i++)
        {
            for(int j = i + 1; j < cubes.size(); j++)
            {
                long long sum = cubes[i] + cubes[j];

                if(sum > n)
                    break;

                freq[sum]++;
            }
        }

        vector<int> result;

        for(auto &[sum, count] : freq)
        {
            if(count >= 2)
                result.push_back(sum);
        }

        sort(result.begin(), result.end());

        return result;
    }
};