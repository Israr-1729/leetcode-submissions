class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size = boxes.size();
        vector<int> result(size);

        for(int i = 0; i<size; i++)
        {
            int sum = 0;
            for(int j = i-1; j>=0 && j<size; j--)
            {
                if(boxes[j]=='1')
                sum += i-j;
            }
            
            for(int j = i+1; j>=0 && j<size; j++)
            {
                if(boxes[j]=='1')
                sum += j-i;
            }
            result[i] = sum;
        }
        return result;
    }
};