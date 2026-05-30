class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int size = bank.size();
        vector<int> numberOfDevices(size);
        for(int i = 0; i<size; i++)
        {
            int number = 0;
            for(int j = 0; j<bank[i].size(); j++)
            {
                if(bank[i][j]=='1')
                {
                    number++;
                }
            }
            numberOfDevices[i] = number;
        }
        int sum = 0;
        int first = 0;
        int second = 0;

        while(second<size && first<size)
        {
            first = second;
            second++;
            while(second<size && numberOfDevices[second]==0)
            second++;
            if(second<size && first<size)
            sum+=numberOfDevices[first] * numberOfDevices[second];
        }
        return sum;
    }
};