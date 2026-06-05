class Solution {
public:
    int minPartitions(string n) {
        int size = n.size();
        int maxm = '0';
        for(int i = 0; i<size; i++)
        {
            maxm = n[i]>maxm? n[i] : maxm;
        }
        return (int)(maxm-48);
    }
};