class Solution {
public:
    bool sameRow(const vector<int>& source, const vector<int>& target)
    {
        return source[0] == target[0];
    }
    bool sameColumn(const vector<int>& source, const vector<int>& target)
    {
        return source[1] == target[1];
    }
    bool sameDiagonal(const vector<int>& source, const vector<int>& target)
    {
        return abs(source[0] - target[0]) == abs(source[1] - target[1]);
    }
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source == target)
        return 0;
        
        if(sameRow(source, target) || sameColumn(source,target) || sameDiagonal(source, target))
        return 1;

        return 2;
    }
};