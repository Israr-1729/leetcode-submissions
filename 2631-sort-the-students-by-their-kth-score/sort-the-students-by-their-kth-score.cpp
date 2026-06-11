class Solution {
public:

    bool isSorted(const vector<vector<int>> &score,const int &k)
    {
        int size = score.size();
        for(int i = 0; i<size-1; i++)
        {
            if(score[i][k]<score[i+1][k])
            return false;
        }
        return true;
    }

    vector<vector<int>> sortRecursively(vector<vector<int>> &score,const int &k)
    {
        if(isSorted(score, k))
        return score;

        else
        {
            int size = score.size();
            for(int i = 0; i<size-1; i++)
            {
                if(score[i][k]<score[i+1][k])
                swap(score[i], score[i+1]);
            }
        }
        return sortRecursively(score, k);
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        return sortRecursively(score, k);
    }
};